/*
 * dcMappingHeuristic.cxx
 *
 *  Created on: Sep 17, 2015
 *      Author: manu
 */
#ifndef MODULES_DREAMCLOUD_PLATFORM_SCLIB_MAPPING_HEURISTIC_RANDOMFIXED_HXX_
#define MODULES_DREAMCLOUD_PLATFORM_SCLIB_MAPPING_HEURISTIC_RANDOMFIXED_HXX_

#include <iostream>
#include <random>

#include "dcMappingHeuristicI.hxx"

using namespace std;

namespace dreamcloud {
namespace platform_sclib {

/**
 * Map the runnables randomly.
 *
 * TAKE CARE: this mapper is partially dependent on the runnables order. The most communicating runnables are mapped depending on their order of arrival. The least communicating runnables are mapped independently from their order of arrival.
 */
class dcMappingHeuristicRandom: public dcMappingHeuristicI {

public:
	// Mapping functions and type definitions
	dcMappingLocation mapRunnable(unsigned long int time,
			const string& runnableId, const string& runnableName,
			const string& taskName, const string& taskId, unsigned int idInTask,
			unsigned int periodId);
	void runnableMapped(unsigned long int time, const string& runnableId);
	dcMappingLocation mapLabel(const string& labelId, unsigned long int time,
			const string& labelName);
	void switchMode(unsigned long int time, const string& newModeFile,
			const string& newModeName);

	// Hardware model functions
	void addCoreType(const string& coreType, double energyMultiplier,
			double switchingPModeTimePenalty,
			double switchingPModeEnergyPenalty, int maxFrequencyInHz,
			map<double, double> voltageToFreq, int voltToFreqLevel);
	void addProcessingCore(const string& name, int x, int y,
			const string& coreType, unsigned int clockRatio,
			unsigned int quartz, unsigned int ticksPerCycle,
			double staticEnergyValue, const string& staticEnergyUnit,
			double energyMultiplier, int pMode);
	void setNocSize(unsigned int NoCXSize, unsigned int NoCYSize);

	// Application model functions
	void setApp(const string& appFile);

	// Platform feedbacks
	void completeRunnable(unsigned long int time, const string& runnableId);
	dcMappingHeuristicRandom(unsigned int seed);

private:
	int xLabel;
	int yLabel;
	int NoCXSize;
	int NoCYSize;

	std::mt19937 gen;
	int seed;

};

}
}
#endif
