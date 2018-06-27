//QuickHex by GeoSn0w (@FCE365)
//This tool dumps any given file into its hex representation. Built for fun.
//Happy dumping!
//~GeoSn0w, June 27 2018

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

size_t read_size;
unsigned char object_buffer[16];
int i, c, offset;
void dump_hex(FILE *object_file, int start_offset);

int main(int argc, char *argv[]){
  printf("QuickHex v1.0 by GeoSn0w (@FCE365)\n\n");
  if (argc < 2){
    printf("[!] Not feeding me any file? It's ok. I can find the exit myself.\n");
    printf("Usage: %s <file path> <start_offset>\n\n", argv[0]);
    exit(EXIT_FAILURE);

  } else if (argc == 2){
    printf("[!] Aside from a file, you need to also specify the beginning offset from where I should start dumping. Specify 0 for the whole file.\n");
    printf("Usage: %s <file path> <start_offset>\n\n", argv[0]);
    exit(EXIT_FAILURE);
  } else if (argc == 3){
    const char *file_path = argv[1];
    FILE *object_file = fopen(file_path, "r");
      if (object_file == NULL){
          fprintf(stderr, "Error opening the file: %s\n",strerror(errno));
          exit(EXIT_FAILURE);
      } else{
          offset = atoi(argv[2]);
          dump_hex(object_file, offset);
      }
    return 0;
  } else if (argc > 3){
    printf("Too many commands!\nUsage: %s <file path> <start_offset>\n\n", argv[0]);
    exit(EXIT_FAILURE);
  }
}

void dump_hex(FILE *object_file, int start_offset){
  fseek(object_file, start_offset, SEEK_SET); //Unwind the file back to the start, offset 0.
  printf("[i] Beginning the HEX dump of the object file...\n");
  offset = 0;
  while ((read_size = fread(object_buffer, 1, sizeof object_buffer, object_file)) > 0) {
      printf("[*] %04x: ", offset);
      offset += 16; // Chunks
      for (i = 0; i < 16; i++){
        printf("%02x ", object_buffer[i]);
      }
      for (i = 0; i < 16; i++) {
          c = object_buffer[i];
          printf("%c", (c >= 33 && c <= 255 ? c : '.')); //We pad with dots.
      }
      printf("\n");
  }
  fclose(object_file); //Always close the file you open :P
  printf("[*] EOF \n"); // EOF = End of File.
  return;
}
