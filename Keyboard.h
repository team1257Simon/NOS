#ifndef KB_H
#define KB_H
void InitKeyboard();
void keyb_handler();
unsigned char getch();
unsigned char kbhit();
char kinput_buffer[255];
#define KSTAT_NORMAL 0
#define KSTAT_SHIFT 1
#define KSTAT_CTRL 2
#define KSTAT_ALT 3
#define KSTAT_CSHIFT 4
#define KSTAT_CALT 5
int kstat_curr = KSTAT_NORMAL;
#endif
