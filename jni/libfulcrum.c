#include <stdio.h>
#include "libfulcrum.h"






long __kexecute(void* sym_addr, ...){
  va_list argp;
  va_start(argp, sym_addr);

  return syscall(SYSCALL_NUMBER, PLUG, sym_addr, va_arg(argp, long), va_arg(argp, long), va_arg(argp, long), va_arg(argp, long), va_arg(argp, long), va_arg(argp, long)); //it doesn't matter if we supply too many arguments because the function will just ignore it lmfao.

}

void* ksymbol(char* sym_name){
  return (void*)syscall(SYSCALL_NUMBER, IGOT5THINGSTOSAY, sym_name, strlen(sym_name)+1);
}

void kread(void* user_buf, void* kbuf, size_t size){
  syscall(SYSCALL_NUMBER, PENJAMINCITY, user_buf, kbuf, size);
}

void kwrite(void* kbuf, void* user_buf, size_t size){
  syscall(SYSCALL_NUMBER, FULCRUM, kbuf, user_buf, size);
}

unsigned char kreadb(void* kbuf){
  return (unsigned char)syscall(SYSCALL_NUMBER, OBLIVIATE, kbuf);
}

unsigned short kreadw(void* kbuf){
  return (unsigned short)syscall(SYSCALL_NUMBER, EXQUISITE, kbuf);
}

unsigned int kreadl(void* kbuf){
  return (unsigned int)syscall(SYSCALL_NUMBER, FADEDTHANAHO, kbuf);
}

unsigned long kreadq(void* kbuf){
  return (unsigned long)syscall(SYSCALL_NUMBER, SHALLWE, kbuf);
}

void kwriteb(void* kbuf, char to_write){
  syscall(SYSCALL_NUMBER, BLINKERTONCITY, kbuf, (long)to_write);
}

void kwritew(void* kbuf, short to_write){
  syscall(SYSCALL_NUMBER, YOUFEELME, kbuf, (long)to_write);
}

void kwritel(void* kbuf, int to_write){
  syscall(SYSCALL_NUMBER, CHEERSMYFRIENDS, kbuf, (long)to_write);
}

void kwriteq(void* kbuf, long to_write){
  syscall(SYSCALL_NUMBER, STIIZYPODS, kbuf, to_write);
}



void* kmalloc(size_t size){
  
  static void* __kmalloc_addr = NULL;
  if(!__kmalloc_addr){
    __kmalloc_addr = ksymbol("__kmalloc");
  }
  
  return (void*)__kexecute(__kmalloc_addr, size);
}

void kfree(void* kbuf){
  static void* kfree_addr = NULL; 
  if(!kfree_addr){
    kfree_addr = ksymbol("kfree");
  }

  __kexecute(kfree_addr, kbuf);
  
}

void* get_phys_memory(void* phys_addr, size_t size){
  return (void*)kexecute("ioremap_cache", phys_addr, size);
}





