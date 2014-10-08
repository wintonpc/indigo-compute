#include <stdio.h>
#include "compute.h"

using namespace std;
using namespace ib::ffi::compute::v3_3_0;

QuantitatedCompound convertedChromatogramToQuantitatedCompound(ConvertedChromatogram cc) {
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
  return qc;
}

QuantitatedSample convertedToQuantitatedSample(ConvertedSample cs) {
  QuantitatedSample qs;
  qs.set_id(cs.id());
  qs.set_name("");
  qs.set_unique_id(cs.unique_id());
  for (ConvertedChromatogram cc : cs.converted_chromatograms())
    *(qs.add_quantitated_compounds()) = convertedChromatogramToQuantitatedCompound(cc);
  return qs;
}

FullSweepResult fullSweep(const FullSweepArgs& args, const FloatsMap& traceTimes, const FloatsMap& traceIntensities,
                          // out params
                          FloatsMap& fullTimes, FloatsMap& plotTimes, FloatsMap& raw,
                          FloatsMap& smooth, FloatsMap& globalBaseline, FloatsMap& plot) {
  
  printf("fullSweep got converted samples with %d total traces\n", (int)traceTimes.size());

  FullSweepResult result;
  for (ConvertedSample cs : args.converted_samples())
    *(result.add_quantitated_samples()) = convertedToQuantitatedSample(cs);

  return result;
}
