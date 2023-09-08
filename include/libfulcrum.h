#ifndef __YODIE_GANG
#define __YODIE_GANG
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

//I AM THE ORIGINAL FULCRUM. FULCRUM COME IN. YUHHHH YODIEGANG.

#define PENJAMINCITY 0xf0 //read
#define FULCRUM 0xf1 //write
#define PLUG 0xf2 //execute
#define IGOT5THINGSTOSAY 0xf3 //symbol

#define OBLIVIATE 0xf4 //readb
#define EXQUISITE 0xf5 //readw
#define FADEDTHANAHO 0xf6 //readl
#define SHALLWE 0xf7 //readq
#define BLINKERTONCITY 0xf8 //writeb
#define YOUFEELME 0xf9 //writew
#define CHEERSMYFRIENDS 0xfa //writel
#define STIIZYPODS 0xfb //writeq

#define SYSCALL_NUMBER 0xfaded


#define kexecute(sym_name, ...) __kexecute(ksymbol(sym_name), __VA_ARGS__) //nice wrapper so you don't have to do ksymbol as well

long __kexecute(void* sym_addr, ...);
void* ksymbol(char* sym_name);
void kread(void* user_buf, void* kbuf, size_t size);
void kwrite(void* kbuf, void* user_buf, size_t size);
void* kmalloc(size_t size);
void kfree(void* kbuf);
unsigned char kreadb(void* kbuf);
unsigned short kreadw(void* kbuf);
unsigned int kreadl(void* kbuf);
unsigned long kreadq(void* kbuf);
void kwriteb(void* kbuf, char to_write);
void kwritew(void* kbuf, short to_write);
void kwritel(void* kbuf, int to_write);
void kwriteq(void* kbuf, long to_write);

void* get_phys_memory(void* phys_addr, size_t size);


#endif
