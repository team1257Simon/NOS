#ifndef KB_H
#define KB_H
void InitKeyboard();
void keyb_handler();
unsigned char getch();
unsigned char kbhit();
char kinput_buffer[255];
char kread_buffer[255];
#define KSTAT_NORMAL 0
#define KSTAT_SHIFT 1
#define KSTAT_CTRL 2
#define KSTAT_ALT 3
#define KSTAT_NUM 4
#define KSTAT_CAPS 5
#define KSTAT_SHFTCAPS 6
#define KSTAT_SHFTNUM 7
int kstat_curr = KSTAT_NORMAL;
#endif