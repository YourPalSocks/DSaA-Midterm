#include "PrecondViolatedExcep.h"

PrecondViolationExcep::PrecondViolationExcep(const string& message):
	logic_error("Precondition Violation Exception: " + message)
{
}