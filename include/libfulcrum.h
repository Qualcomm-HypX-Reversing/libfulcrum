#ifndef __YODIE_GANG
#define __YODIE_GANG
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

//I AM THE ORIGINAL FULCRUM. FULCRUM COME IN. YUHHHH YODIEGANG.

#define PENJAMINCITY 0xf0
#define READ PENJAMINCITY
#define FULCRUM 0xf1
#define WRITE FULCRUM
#define PLUG 0xf2
#define EXECUTE PLUG
#define IGOT5THINGSTOSAY 0xf3
#define SYMBOL IGOT5THINGSTOSAY

#define SYSCALL_NUMBER 0xfaded

long kexecute(void* sym_addr, ...);
void* ksymbol(char* sym_name);
void kread(void* user_buf, void* kbuf, size_t size);
void kwrite(void* kbuf, void* user_buf, size_t size);
void* kmalloc(size_t size);
void kfree(void* kbuf);




#endif
