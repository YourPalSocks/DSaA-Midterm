/*
* PrecondViolatedExep class as seen on page 249
*/

#pragma once
#ifndef _PRECOND_VIOLATED_EXEP
#define _PRECOND_VIOLATED_EXEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolationExcep : public logic_error
{
public:
	PrecondViolationExcep(const string& message = "");
};
#endif