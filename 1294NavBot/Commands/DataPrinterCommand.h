#ifndef DATAPRINTERCOMMAND_H
#define DATAPRINTERCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class DataPrinterCommand: public CommandBase
{
public:
	DataPrinterCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
