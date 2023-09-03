#include <stdio.h>
#include <sys/syscall.h>      /* Definition of SYS_* constants */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libfulcrum.h"




long kexecute(void* sym_addr, ...){
  va_list argp;

  return syscall(SYSCALL_NUMBER, PLUG, va_arg(argp, long), va_arg(argp, long), va_arg(argp, long), va_arg(argp, long), va_arg(argp, long), va_arg(argp, long)); //it doesn't matter if we supply too many arguments because the function will just ignore it lmfao.

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


void* kmalloc(size_t size){
  static void* __kmalloc_addr = NULL;
  
  if(!__kmalloc_addr){
   __kmalloc_addr = ksymbol("__kmalloc");
  }

  return (void*)kexecute(__kmalloc_addr, size);
}

void kfree(void* kbuf){
  static void* kfree_addr = NULL;
  if(!kfree_addr){
    kfree_addr = ksymbol("kfree");
  }

  kexecute(kfree_addr, kbuf);
  
}



/*
int main()
{
  char* __kmalloc = "__kmalloc";
  void* __kmalloc_addr = 
  printf("__kmalloc: %p\n", __kmalloc_addr);
  //execute
  void* kbuf = (void*)syscall(0xfaded, PLUG, __kmalloc_addr, 0x8);

  printf("kbuf: %p\n", kbuf);



  char* qcom_smem_get = "qcom_smem_get";
  void* qcom_smem_get_addr = (void*)syscall(0xfaded, IGOT5THINGSTOSAY, qcom_smem_get, strlen(qcom_smem_get)+1);

  printf("%s: %p\n", qcom_smem_get, qcom_smem_get_addr);

  void* part_table_start = (void*)syscall(0xfaded, PLUG, qcom_smem_get_addr, (long)-1, 0x192, kbuf);

  printf("Partition table start: %p\n", part_table_start);

  size_t part_table_size = 0;

  syscall(0xfaded, PENJAMINCITY, &part_table_size, kbuf, sizeof(part_table_size));

  printf("Partition table size: %p", (void*)part_table_size);

  void* partition_table = malloc(part_table_size);

  syscall(0xfaded, PENJAMINCITY, partition_table, part_table_start, part_table_size);

  int fd = open("part_table_dump", O_CREAT | O_WRONLY | O_TRUNC, 00777);

  if(fd < 0){
    printf("Failed to open fd\n");
    return -1;
  }

  write(fd, partition_table, part_table_size);



  
  return 0;
}
*/