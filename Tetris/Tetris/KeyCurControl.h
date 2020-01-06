#pragma once
#ifndef _KEY_CUR_CONTROL_
#define	_KEY_CUR_CONTROL_
#include "point.h"
void RemoveCursor(void);
point GetCurrentCursorPos(void);
void SetCurrentCursorPos(int x, int y);
void InitKeyDelayRate(int rate);
void ProcessKeyInput(void);
#endif