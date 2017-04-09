#ifndef MENU_UTILS_H
#define MENU_UTILS_H

void menu_prompt(void);
void unknown_command_prompt(void);
void no_current_image_prompt(void);
void cropping_failed_prompt(void);
void option_r_msg(char filename[]);
void option_w_msg(char filename[]);
void option_c_msg(int x1, int y1, int x2, int y2);
void option_i_msg(void);
void option_s_msg(void);
void option_g_msg(void);
void option_b_msg(float change);
void exitMsg(void);
void promptDelta(void);
void runMenu(void);

#endif