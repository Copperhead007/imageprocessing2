#include <stdint.h>
#include <cstdio>
#include <complex>
#include <cmath>

// function 
void ip(int H, int W, int choice) {
   unsigned char buffer[H][W];
   unsigned char outimg[H][W];
   float xfilter[9] = {-1,0,1,-2,0,2,-1,0,1};
   float yfilter[9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
   float xfive[25] = {-1, -2, 0, 2, 1, -1, -2, 0, 2, 1, -1, -2, 0, 2, 1, -1, -2, 0, 2, 1, -1, -2, 0, 2, 1};
   float yfive[25] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1};
   int i = 0, j = 0;
   float sum = 0,p = 0, pl = 0, pr = 0, pu = 0, pd = 0, ptl = 0, ptopr = 0, pbl = 0, pbr = 0;
   float a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, l = 0;
   float m = 0, n = 0, o = 0, t = 0, q = 0, r = 0, s = 0;

   FILE * fp = fopen("blackball.raw", "rb");
   fread(buffer, H*W, 1, fp);

        //loops through all images and writes to output files
    //int p = 0, pl = 0, pr = 0, pu = 0, pd = 0, ptl = 0, ptopr = 0, pbl = 0, pbr = 0;
    if(choice == 0){
     for(i = 0; i < (H); i++){
        for(j = 0; j < (W); j++){
            //these hold the value of an images pixel and set to temp value for operations
            //printf("%x\n",buffer[i][j]);
            ptl = buffer[i-1][j-1] * xfilter[0];
            pu = buffer[i-1][j] * xfilter[1];
            ptopr = buffer[i-1][j+1] * xfilter[2];
            pl = buffer[i][j-1] * xfilter[3];
            p = buffer[i][j] * xfilter[4];
            pr = buffer[i][j+1] * xfilter[5];
            pbl = buffer[i+1][j-1] * xfilter[6];
            pd = buffer[i+1][j] * xfilter[7];
            pbr = buffer[i+1][j+1] * xfilter[8];

            sum = ptl + pu + ptopr + pl + p + pr + pbl + pd + pbr;
            if(sum > 255){
                sum = 255;
            }
            else if (sum < 0)
            {
                sum = 0;
            }
            else{
                sum = sum;
            }
            //these are operations performed on each image when looping through pixel by pixel
            outimg[i][j] = sum;
            //printf("%x %x\n", outimage[i][j],buffer[i][j]);
        }
    }
    }
    if(choice == 1){
     for(i = 0; i < H; i++){
        for(j = 0; j < W; j++){
            //these hold the value of an images pixel and set to temp value for operations
            //printf("%x\n",buffer[i][j]);
            ptl = buffer[i-1][j-1] * yfilter[0];
            pu = buffer[i-1][j] * yfilter[1];
            ptopr = buffer[i-1][j+1] * yfilter[2];
            pl = buffer[i][j-1] * yfilter[3];
            p = buffer[i][j] * yfilter[4];
            pr = buffer[i][j+1] * yfilter[5];
            pbl = buffer[i+1][j-1] * yfilter[6];
            pd = buffer[i+1][j] * yfilter[7];
            pbr = buffer[i+1][j+1] * yfilter[8];

            sum = ptl + pu + ptopr + pl + p + pr + pbl + pd + pbr;
            if(sum > 255){
                sum = 255;
            }
            else if (sum < 0)
            {
                sum = 0;
            }
            else{
                sum = sum;
            }
            //these are operations performed on each image when looping through pixel by pixel
            outimg[i][j] = sum;
            //printf("%x %x\n", outimage[i][j],buffer[i][j]);
        }
    }
    }
    if(choice == 2){
     for(i = 0; i < H; i++){
        for(j = 0; j < W; j++){
            //these hold the value of an images pixel and set to temp value for operations
            //printf("%x\n",buffer[i][j]);
            a = buffer[i-2][j-2] * xfive[0];
            b = buffer[i-2][j-1] * xfive[0];
            c = buffer[i-2][j] * xfive[0];
            d = buffer[i-2][j+1] * xfive[0];
            e = buffer[i-2][j+2] * xfive[0];
            f = buffer[i-1][j-2] * xfive[0];
            g = buffer[i-1][j-1] * xfive[0];
            h = buffer[i-1][j] * xfive[0];
            ptl = buffer[i-1][j+1] * xfive[0];
            pu = buffer[i-1][j+2] * xfive[1];
            ptopr = buffer[i][j-2] * xfive[2];
            pl = buffer[i][j-1] * xfive[3];
            p = buffer[i][j] * xfive[4];
            pr = buffer[i][j+1] * xfive[5];
            pbl = buffer[i][j+2] * xfive[6];
            pd = buffer[i+1][j-2] * xfive[7];
            pbr = buffer[i+1][j-1] * xfive[8];
            l = buffer[i+1][j] * xfive[0];
            m = buffer[i+1][j+1] * xfive[0];
            n = buffer[i+1][j+2] * xfive[0];
            o = buffer[i+2][j-2] * xfive[0];
            t = buffer[i+2][j-1] * xfive[0];
            q = buffer[i+2][j] * xfive[0];
            r = buffer[i+2][j+1] * xfive[0];
            s = buffer[i+2][j+2] * xfive[0];

            sum = ptl + pu + ptopr + pl + p + pr + pbl + pd + pbr + a + b + c + d + e + f + g + h + l + m + n + o + t + q + r + s;
            if(sum > 255){
                sum = 255;
            }
            else if (sum < 0)
            {
                sum = 0;
            }
            else{
                sum = sum;
            }
            //these are operations performed on each image when looping through pixel by pixel
            outimg[i][j] = sum;
            //printf("%x %x\n", outimage[i][j],buffer[i][j]);
        }
    }
    }
    if(choice== 3){
     for(i = 0; i < H; i++){
        for(j = 0; j < W; j++){
            a = buffer[i-2][j-2] * yfive[0];
            b = buffer[i-2][j-1] * yfive[0];
            c = buffer[i-2][j] * yfive[0];
            d = buffer[i-2][j+1] * yfive[0];
            e = buffer[i-2][j+2] * yfive[0];
            f = buffer[i-1][j-2] * yfive[0];
            g = buffer[i-1][j-1] * yfive[0];
            h = buffer[i-1][j] * yfive[0];
            ptl = buffer[i-1][j+1] * yfive[0];
            pu = buffer[i-1][j+2] * yfive[1];
            ptopr = buffer[i][j-2] * yfive[2];
            pl = buffer[i][j-1] * yfive[3];
            p = buffer[i][j] * yfive[4];
            pr = buffer[i][j+1] * yfive[5];
            pbl = buffer[i][j+2] * yfive[6];
            pd = buffer[i+1][j-2] * yfive[7];
            pbr = buffer[i+1][j-1] * yfive[8];
            l = buffer[i+1][j] * yfive[0];
            m = buffer[i+1][j+1] * yfive[0];
            n = buffer[i+1][j+2] * yfive[0];
            o = buffer[i+2][j-2] * yfive[0];
            t = buffer[i+2][j-1] * yfive[0];
            q = buffer[i+2][j] * yfive[0];
            r = buffer[i+2][j+1] * yfive[0];
            s = buffer[i+2][j+2] * yfive[0];

            sum = ptl + pu + ptopr + pl + p + pr + pbl + pd + pbr + a + b + c + d + e + f + g + h + l + m + n + o + t + q + r + s;
            if(sum > 255){
                sum = 255;
            }
            else if (sum < 0)
            {
                sum = 0;
            }
            else{
                sum = sum;
            }
            //these are operations performed on each image when looping through pixel by pixel
            outimg[i][j] = sum;
            //printf("%x %x\n", outimage[i][j],buffer[i][j]);
        }
    }
    }
    //after ifs
    FILE * fp2 = fopen("blackball5Vout.raw", "wb");

    fwrite(outimg, H*W, 1, fp2);

    fclose(fp);
    fclose(fp2);
    return;
}

int main(){
    //height and width of all images
    int H = 750;
    int W = 500;
    ip(750, 500, 3);
    //2D array of 0s Buffer is used to hold data from file pointer
    //Sobel Operators for difference operations
    //Convolve with 3*3 H/V & 5*5 H/V for 3 images = 12 images
    //first image
    //unsigned char out1imgthreeH[H][W];
    
    return 0;
}

/*
    outimageReverse[i][j] = 255 - a;
    outimageAddLess[i][j] = b + 20;
    outimageAddMore[i][j] = c + 128;
      printf("%x\n",buffer[-1][-1]);
    printf("%x\n",buffer[-1][0]);
    printf("%x\n",buffer[-1][1]);
    printf("%x\n",buffer[0][-1]);
    printf("%x\n",buffer[0][0]);
    printf("%x\n",buffer[0][1]);
    printf("%x\n",buffer[1][-1]);
    printf("%x\n",buffer[1][0]);
    printf("%x\n",buffer[1][1]);

    FILE * fp2 = fopen("sobel1h3.raw","wb");
    FILE * fp3 = fopen("sobel1v3.raw","wb");
    FILE * fp4 = fopen("sobel1h5.raw","wb");
    FILE * fp5 = fopen("sobel1v5.raw","wb");

    FILE * fp6 = fopen("sobel2h3.raw","wb");
    FILE * fp7 = fopen("sobel2v3.raw","wb");
    FILE * fp8 = fopen("sobel2h5.raw","wb");
    FILE * fp9 = fopen("sobel2v5.raw","wb");

    FILE * fp10 = fopen("sobel3h3.raw","wb");
    FILE * fp11 = fopen("sobel3v3.raw","wb");
    FILE * fp12 = fopen("sobel3h5.raw","wb");
    FILE * fp13 = fopen("sobel3v5.raw","wb");
    
    fwrite(outimageReverse, H*W,1, fp2);
    fwrite(outimageAddLess, H*W,1, fp3);
    fwrite(outimageAddMore, H*W,1, fp4);

    fclose(fp);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);
    fclose(fp7);
    fclose(fp8);
    fclose(fp9);
    fclose(fp10);
    fclose(fp11);
    fclose(fp12);
    fclose(fp13);
    */
