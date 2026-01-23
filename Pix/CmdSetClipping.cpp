#include "CmdSetClipping.h"
#include "Clipper.h"

bool CmdSetClipping::Execute(const std::vector <std::string>& params)
{
	if (params.size() != 1)
	{
		return false;
	}

	std::string clipBoolean = params[0];

	//std::transform(clipBoolean.begin(), clipBoolean.end(), clipBoolean.begin(), [](unsigned char c) { return std::tolower(c); });

	if (clipBoolean == "true")
	{
		Clipper::Get()->SetClipping(true);
	}
	else if (clipBoolean == "false")
	{
		Clipper::Get()->SetClipping(false);
	}
}