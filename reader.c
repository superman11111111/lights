#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
        char fn[255];
        memcpy(fn, argv[1], 255);
        printf("File: %s\n", fn); 
        FILE* fp;
        fp = fopen(fn, "rb");

        unsigned char buff[5];
        char c[2];
        buff[4] = '\0';
        int chunk_size[4];
        fread(&buff, 4, 1, fp);
        printf("\nChunkID: %s\n", buff);
        fread(&buff, 4, 1, fp);
        chunk_size[0] = *(int*)buff;
        printf("Size: %d\n", chunk_size[0]); 
        fread(&buff, 4, 1, fp);
        printf("%s\n", buff);

        fread(&buff, 4, 1, fp);
        printf("\nChunkID: %s\n", buff);
        fread(&buff, 4, 1, fp);
        chunk_size[1] = *(int*)buff;
        printf("Size: %d\n", chunk_size[1]);
        fread(&c, 2, 1, fp);
        printf("AudioFormat: %d\n", c[0]|c[1]<<8);
        fread(&c, 2, 1, fp);
        printf("NumChannels: %d\n", c[0]|c[1]<<8);
        fread(&buff, 4, 1, fp);
        printf("SampleRate: %d\n", *(int*)buff);
        fread(&buff, 4, 1, fp);
        printf("ByteRate: %d\n", *(int*)buff);
        fread(&c, 2, 1, fp);
        printf("BlockAlign: %d\n", c[0]|c[1]<<8);
        fread(&c, 2, 1, fp);
        printf("BitsPerSample: %d\n", c[0]|c[1]<<8);

        fread(&buff, 4, 1, fp);
        printf("\nChunkID: %s\n", buff); 
        fread(&buff, 4, 1, fp);
        chunk_size[2] = *(int*)buff/4; 
        printf("Size: %d\n", chunk_size[2]); 
        int l;
        int r;
        for(int i = 0; i < chunk_size[2]; i++)
        {
                fread(&buff, 4, 1, fp);
                l = (buff[1]<<8)+buff[0];
                r = (buff[3]<<8)+buff[2];
                printf("%d: %d %d\n", i, l, r);
        }





        return 0;
}


