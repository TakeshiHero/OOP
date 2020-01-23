#pragma once
#include <string>
#include "TeamPart.h"
using namespace std;

class Session {
public:
	TeamPart TeamRed[5];
	TeamPart TeamBlue[5];
	string Winner;
	Session() {}
};