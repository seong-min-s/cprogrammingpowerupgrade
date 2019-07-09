#ifndef _BLOCK_STAGE_CONTROL_H_
#define _BLOCK_STAGE_CONTROL_H_

void InitNewBlockPos(int x, int y);
void ChooseBlock(void);
int GetCurrentBlockIdx(void);
void ShowBlock(char blockInfo[][4]);
void DeleteBlock(char blockInfo[][4]);
void BlockDown(void);
#endif