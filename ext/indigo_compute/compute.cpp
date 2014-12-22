#include <stdio.h>
#include "compute.h"

using namespace std;
using namespace ib::ffi::compute::v3_3_0;

QuantitatedCompound convertedChromatogramToQuantitatedCompound(ConvertedChromatogram cc, const RawTraces& rawTraces,
                                                               QuantTraces& quantTraces) {
  QuantitatedCompound qc;
  qc.set_id("");
  string name = "";
  if (cc.has_precursor())
    name += std::to_string(cc.precursor()) + "-";
  name += std::to_string(cc.product());
  name += " " + cc.polarity();
  if (cc.has_collision_energy())
    name += " @" + std::to_string(cc.collision_energy());
  qc.set_name(name);

  QuantitatedChromatogram theChrom;
  theChrom.set_id(cc.id());
  theChrom.set_name("Quant");

  *(qc.add_quantitated_chromatograms()) = theChrom;

  printf("looking up rawTrace times for %s\n", cc.id().c_str());
  quantTraces.fullTimes[theChrom.id()] = rawTraces.times.at(cc.id());

  return qc;
}

QuantitatedSample convertedToQuantitatedSample(ConvertedSample cs, const RawTraces& rawTraces,
                                               QuantTraces& quantTraces) {
  QuantitatedSample qs;
  qs.set_id(cs.id());
  qs.set_name("");
  qs.set_unique_id(cs.unique_id());
  for (ConvertedChromatogram cc : cs.converted_chromatograms())
    *(qs.add_quantitated_compounds()) = convertedChromatogramToQuantitatedCompound(cc, rawTraces, quantTraces);
  return qs;
}

FullSweepResult fullSweep(const FullSweepArgs& args, const RawTraces& rawTraces,
                          QuantTraces& quantTraces) {
  
  printf("fullSweep got converted samples with %d total traces\n", (int)rawTraces.times.size());

  FullSweepResult result;
  for (ConvertedSample cs : args.converted_samples())
    *(result.add_quantitated_samples()) = convertedToQuantitatedSample(cs, rawTraces, quantTraces);

  return result;
}
