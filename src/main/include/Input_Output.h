#pragma once

// Local
#include "lib/include/Component.h"
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"

class Input_Output : public Component
{
public:
	void PreStepCallback() override;
	void PostStepCallback() override;
private:
};
