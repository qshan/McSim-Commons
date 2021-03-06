/*
 * dcMappingHeuristic.cxx
 *
 *  Created on: Sep 17, 2015
 *      Author: manu
 */
#ifndef MODULES_DREAMCLOUD_PLATFORM_SCLIB_MAPPING_HEURISTIC_MINCOM_HXX_
#define MODULES_DREAMCLOUD_PLATFORM_SCLIB_MAPPING_HEURISTIC_MINCOM_HXX_

#include <map>

#include "dcMappingHeuristicI.hxx"
#include "../parser/dcRunnableCall.h"

namespace dreamcloud {
namespace platform_sclib {

class dcMappingHeuristicMinComm: public dcMappingHeuristicI {

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

	void setRunnables(vector<DCApplication::dcRunnableCall *> runnables);

	dcMappingHeuristicMinComm();

private:
	int xRunnable;
	int yRunnable;
	int xLabel;
	int yLabel;
	int NoCXSize;
	int NoCYSize;
	std::map<string, dcMappingLocation> labelsMapping;
	std::map<string, string> runnableIdToBiggestLabelId;
};

}
}
#endif
