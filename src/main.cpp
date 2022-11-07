#include <stdint.h>
#include <cstdio>
#include <complex>
#include <cmath>

// function 
void ip(int H, int W, int choice) {
   unsigned char buffer[H][W];
   unsigned char outimg[H][W];
   int sum = 0;
   int yfilter[9] = {-1,0,1,-2,0,2,-1,0,1};
   int xfilter[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
   int yfive[25] = {-1, -2, 0, 2, 1, -2, -4, 0, 4, 2, -4, -8, 0, 8, 4, -2, -4, 0, 4, 2, -1, -2, 0, 2, 1};
   int xfive[25] = {1, 2, 4, 2 ,1, 2, 4, 8, 4, 2, 0, 0, 0, 0, 0, -2, -4, -8, -4, -2, -1, -2, -4 -2, -1};
   int i = 0, j = 0;
   int p = 0, pl = 0, pr = 0, pu = 0, pd = 0, ptl = 0, ptopr = 0, pbl = 0, pbr = 0;
   int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, l = 0;
   int m = 0, n = 0, o = 0, t = 0, q = 0, r = 0, s = 0;

     int check1 = 0, check2 = 0;

   
    //manually change depending on image raw being manipulated
   FILE * fp = fopen("beach.raw", "rb");
   fread(buffer, H*W, 1, fp);

    /* Checking Buffer
    printf("%x\n",buffer[i][j]);
    for(check1 = 0; check1 < H; check1++){
        printf("%x\n",buffer[check1][check2]);
        for(check2 = 0; check2 < W; check2++){
            printf("%x ",buffer[check1][check2]);
        }
   }
   */

    //loops through images and writes to output files
    //int p = 0, pl = 0, pr = 0, pu = 0, pd = 0, ptl = 0, ptopr = 0, pbl = 0, pbr = 0;
    if(choice == 0){
     for(i = 0; i < H; i++){
        //printf("%d\n", sum);
        for(j = 0; j < W; j++){
            //these hold the value of an images pixel and set bounds for operations
            if((i-1) < 0 || (i-1) >= H || (j-1) < 0 || (j-1) >= W){
                ptl = 0;
            }
            else{
                ptl = buffer[i-1][j-1] * xfilter[0];
            }
            if((i-1) < 0 || (i-1) >= H || (j) < 0 || (j) >= W){
                pu = 0;
            }
            else{
                pu = buffer[i-1][j] * xfilter[1];
            }
            if((i-1) < 0 || (i-1) >= H || (j+1) < 0 || (j+1) >= W){
                ptopr = 0;
            }
            else{
                ptopr = buffer[i-1][j+1] * xfilter[2];
            }
            if((i) < 0 || (i) >= H || (j-1) < 0 || (j-1) >= W){
                pl = 0;
            }
            else{
                pl = buffer[i][j-1] * xfilter[3];
            }
            if((i) < 0 || (i) >= H || (j) < 0 || (j) >= W){
                p = 0;
            }
            else{
                p = buffer[i][j] * xfilter[4];
            }
            if((i) < 0 || (i) >= H || (j+1) < 0 || (j+1) >= W){
                pr = 0;
            }
            else{
                pr = buffer[i][j+1] * xfilter[5];
            }
            if((i+1) < 0 || (i+1) >= H || (j-1) < 0 || (j-1) >= W){
                pbl = 0;
            }
            else{
                pbl = buffer[i+1][j-1] * xfilter[6];
            }
            if((i+1) < 0 || (i+1) >= H || (j) < 0 || (j) >= W){
                pd = 0;
            }
            else{
                pd = buffer[i+1][j] * xfilter[7];
            }
            if((i+1) < 0 || (i+1) >= H || (j+1) < 0 || (j+1) >= W){
                pbr = 0;
            }
            else{
                pbr = buffer[i+1][j+1] * xfilter[8];
            }
            
            sum = (ptl + pu + ptopr + pl + p + pr + pbl + pd + pbr) / 8 + 128;
            
            //printf("%d ", sum);
            //assigning result to single pixel
            outimg[i][j] = sum;
            //printf("%x %x\n", outimage[i][j],buffer[i][j]);
        }
    }
    }
    if(choice == 1){
     for(i = 0; i < H; i++){
        for(j = 0; j < W; j++){

            if((i-1) < 0 || (i-1) >= H || (j-1) < 0 || (j-1) >= W){
                ptl = 0;
            }
            else{
                ptl = buffer[i-1][j-1] * yfilter[0];
            }
            if((i-1) < 0 || (i-1) >= H || (j) < 0 || (j) >= W){
                pu = 0;
            }
            else{
                pu = buffer[i-1][j] * yfilter[1];
            }
            if((i-1) < 0 || (i-1) >= H || (j+1) < 0 || (j+1) >= W){
                ptopr = 0;
            }
            else{
                ptopr = buffer[i-1][j+1] * yfilter[2];
            }
            if((i) < 0 || (i) >= H || (j-1) < 0 || (j-1) >= W){
                pl = 0;
            }
            else{
                pl = buffer[i][j-1] * yfilter[3];
            }
            if((i) < 0 || (i) >= H || (j) < 0 || (j) >= W){
                p = 0;
            }
            else{
                p = buffer[i][j] * yfilter[4];
            }
            if((i) < 0 || (i) >= H || (j+1) < 0 || (j+1) >= W){
                pr = 0;
            }
            else{
                pr = buffer[i][j+1] * yfilter[5];
            }
            if((i+1) < 0 || (i+1) >= H || (j-1) < 0 || (j-1) >= W){
                pbl = 0;
            }
            else{
                pbl = buffer[i+1][j-1] * yfilter[6];
            }
            if((i+1) < 0 || (i+1) >= H || (j) < 0 || (j) >= W){
                pd = 0;
            }
            else{
                pd = buffer[i+1][j] * yfilter[7];
            }
            if((i+1) < 0 || (i+1) >= H || (j+1) < 0 || (j+1) >= W){
                pbr = 0;
            }
            else{
                pbr = buffer[i+1][j+1] * yfilter[8];
            }
            
            sum = (ptl + pu + ptopr + pl + p + pr + pbl + pd + pbr) / 8 + 128;
            
            outimg[i][j] = sum;
        }
    }
    }
    if(choice == 2){
     for(i = 0; i < H; i++){
        for(j = 0; j < W; j++){
            //these hold the value of an images pixel and set to temp value for operations
            //printf("%x\n",buffer[i][j]);
            if((i-2) < 0 || (i-2) >= H || (j-2) < 0 || (j-2) >= W){
                a = 0;
            }
            else{
                a = buffer[i-2][j-2] * xfive[0];
            }
            if((i-2) < 0 || (i-2) >= H || (j-1) < 0 || (j-1) >= W){
                b = 0;
            }
            else{
                b = buffer[i-2][j-1] * xfive[1];
            }
            if((i-2) < 0 || (i-2) >= H || (j) < 0 || (j) >= W){
                c = 0;
            }
            else{
                c = buffer[i-2][j] * xfive[2];
            }
            if((i-2) < 0 || (i-2) >= H || (j+1) < 0 || (j+1) >= W){
                d = 0;
            }
            else{
                d = buffer[i-2][j+1] * xfive[3];
            }
            if((i-2) < 0 || (i-2) >= H || (j+2) < 0 || (j+2) >= W){
                e = 0;
            }
            else{
                e = buffer[i-2][j+2] * xfive[4];
            }
            if((i-2) < 0 || (i-2) >= H || (j-2) < 0 || (j-2) >= W){
                f = 0;
            }
            else{
                f = buffer[i-1][j-2] * xfive[5];
            }
            if((i-1) < 0 || (i-1) >= H || (j-1) < 0 || (j-1) >= W){
                g = 0;
            }
            else{
                g = buffer[i-1][j-1] * xfive[6];
            }
            if((i-1) < 0 || (i-1) >= H || (j) < 0 || (j) >= W){
                h = 0;
            }
            else{
                h = buffer[i-1][j] * xfive[7];
            }
            if((i-1) < 0 || (i-1) >= H || (j+1) < 0 || (j+1) >= W){
                ptl = 0;
            }
            else{
                ptl = buffer[i-1][j+1] * xfive[8];
            }
            if((i-1) < 0 || (i-1) >= H || (j+2) < 0 || (j+2) >= W){
                pu = 0;
            }
            else{
                pu = buffer[i-1][j+2] * xfive[9];
            }
            if((i) < 0 || (i) >= H || (j-2) < 0 || (j-2) >= W){
                ptopr = 0;
            }
            else{
                ptopr = buffer[i][j-2] * xfive[10];
            }
            if((i) < 0 || (i) >= H || (j-1) < 0 || (j-1) >= W){
                pl = 0;
            }
            else{
                pl = buffer[i][j-1] * xfive[11];
            }
            if((i) < 0 || (i) >= H || (j) < 0 || (j) >= W){
                p = 0;
            }
            else{
                p = buffer[i][j] * xfive[12];
            }
            if((i) < 0 || (i) >= H || (j+1) < 0 || (j+1) >= W){
                pr = 0;
            }
            else{
                pr = buffer[i][j+1] * xfive[13];
            }
            if((i) < 0 || (i) >= H || (j+2) < 0 || (j+2) >= W){
                pbl = 0;
            }
            else{
                pbl = buffer[i][j+2] * xfive[14];
            }
            if((i+1) < 0 || (i+1) >= H || (j-2) < 0 || (j-2) >= W){
                pd = 0;
            }
            else{
                pd = buffer[i+1][j-2] * xfive[15];
            }
            if((i+1) < 0 || (i+1) >= H || (j-1) < 0 || (j-1) >= W){
                pbr = 0;
            }
            else{
                pbr = buffer[i+1][j-1] * xfive[16];
            }
            if((i+1) < 0 || (i+1) >= H || (j) < 0 || (j) >= W){
                l = 0;
            }
            else{
                l = buffer[i+1][j] * xfive[17];
            }
            if((i+1) < 0 || (i+1) >= H || (j+1) < 0 || (j+1) >= W){
                m = 0;
            }
            else{
                m = buffer[i+1][j+1] * xfive[18];
            }
            if((i+1) < 0 || (i+1) >= H || (j+2) < 0 || (j+2) >= W){
                n = 0;
            }
            else{
                n = buffer[i+1][j+2] * xfive[19];
            }
            if((i+2) < 0 || (i+2) >= H || (j-2) < 0 || (j-2) >= W){
                o = 0;
            }
            else{
                o = buffer[i+2][j-2] * xfive[20];
            }
            if((i+2) < 0 || (i+2) >= H || (j-1) < 0 || (j-1) >= W){
                t = 0;
            }
            else{
                t = buffer[i+2][j-1] * xfive[21];
            }
            if((i+2) < 0 || (i+2) >= H || (j) < 0 || (j) >= W){
                q = 0;
            }
            else{
                q = buffer[i+2][j] * xfive[22];
            }
            if((i+2) < 0 || (i+2) >= H || (j+1) < 0 || (j+1) >= W){
                r = 0;
            }
            else{
                r = buffer[i+2][j+1] * xfive[23];
            }
            if((i+2) < 0 || (i+2) >= H || (j+2) < 0 || (j+2) >= W){
                s = 0;
            }
            else{
                s = buffer[i+2][j+2] * xfive[24];
            }
            
            sum = (ptl + pu + ptopr + pl + p + pr + pbl + pd + pbr + a + b + c + d + e + f + g + h + l + m + n + o + t + q + r + s) / 60 + 128;
            //these are operations performed on each image when looping through pixel by pixel
            outimg[i][j] = sum;
            //printf("%x %x\n", outimage[i][j],buffer[i][j]);
        }
    }
    }
    if(choice == 3){
     for(i = 0; i < H; i++){
        for(j = 0; j < W; j++){

            if((i-2) < 0 || (i-2) >= H || (j-2) < 0 || (j-2) >= W){
                a = 0;
            }
            else{
                a = buffer[i-2][j-2] * yfive[0];
            }
            if((i-2) < 0 || (i-2) >= H || (j-1) < 0 || (j-1) >= W){
                b = 0;
            }
            else{
                b = buffer[i-2][j-1] * yfive[1];
            }
            if((i-2) < 0 || (i-2) >= H || (j) < 0 || (j) >= W){
                c = 0;
            }
            else{
                c = buffer[i-2][j] * yfive[2];
            }
            if((i-2) < 0 || (i-2) >= H || (j+1) < 0 || (j+1) >= W){
                d = 0;
            }
            else{
                d = buffer[i-2][j+1] * yfive[3];
            }
            if((i-2) < 0 || (i-2) >= H || (j+2) < 0 || (j+2) >= W){
                e = 0;
            }
            else{
                e = buffer[i-2][j+2] * yfive[4];
            }
            if((i-2) < 0 || (i-2) >= H || (j-2) < 0 || (j-2) >= W){
                f = 0;
            }
            else{
                f = buffer[i-1][j-2] * yfive[5];
            }
            if((i-1) < 0 || (i-1) >= H || (j-1) < 0 || (j-1) >= W){
                g = 0;
            }
            else{
                g = buffer[i-1][j-1] * yfive[6];
            }
            if((i-1) < 0 || (i-1) >= H || (j) < 0 || (j) >= W){
                h = 0;
            }
            else{
                h = buffer[i-1][j] * yfive[7];
            }
            if((i-1) < 0 || (i-1) >= H || (j+1) < 0 || (j+1) >= W){
                ptl = 0;
            }
            else{
                ptl = buffer[i-1][j+1] * yfive[8];
            }
            if((i-1) < 0 || (i-1) >= H || (j+2) < 0 || (j+2) >= W){
                pu = 0;
            }
            else{
                pu = buffer[i-1][j+2] * yfive[9];
            }
            if((i) < 0 || (i) >= H || (j-2) < 0 || (j-2) >= W){
                ptopr = 0;
            }
            else{
                ptopr = buffer[i][j-2] * yfive[10];
            }
            if((i) < 0 || (i) >= H || (j-1) < 0 || (j-1) >= W){
                pl = 0;
            }
            else{
                pl = buffer[i][j-1] * yfive[11];
            }
            if((i) < 0 || (i) >= H || (j) < 0 || (j) >= W){
                p = 0;
            }
            else{
                p = buffer[i][j] * yfive[12];
            }
            if((i) < 0 || (i) >= H || (j+1) < 0 || (j+1) >= W){
                pr = 0;
            }
            else{
                pr = buffer[i][j+1] * yfive[13];
            }
            if((i) < 0 || (i) >= H || (j+2) < 0 || (j+2) >= W){
                pbl = 0;
            }
            else{
                pbl = buffer[i][j+2] * yfive[14];
            }
            if((i+1) < 0 || (i+1) >= H || (j-2) < 0 || (j-2) >= W){
                pd = 0;
            }
            else{
                pd = buffer[i+1][j-2] * yfive[15];
            }
            if((i+1) < 0 || (i+1) >= H || (j-1) < 0 || (j-1) >= W){
                pbr = 0;
            }
            else{
                pbr = buffer[i+1][j-1] * yfive[16];
            }
            if((i+1) < 0 || (i+1) >= H || (j) < 0 || (j) >= W){
                l = 0;
            }
            else{
                l = buffer[i+1][j] * yfive[17];
            }
            if((i+1) < 0 || (i+1) >= H || (j+1) < 0 || (j+1) >= W){
                m = 0;
            }
            else{
                m = buffer[i+1][j+1] * yfive[18];
            }
            if((i+1) < 0 || (i+1) >= H || (j+2) < 0 || (j+2) >= W){
                n = 0;
            }
            else{
                n = buffer[i+1][j+2] * yfive[19];
            }
            if((i+2) < 0 || (i+2) >= H || (j-2) < 0 || (j-2) >= W){
                o = 0;
            }
            else{
                o = buffer[i+2][j-2] * yfive[20];
            }
            if((i+2) < 0 || (i+2) >= H || (j-1) < 0 || (j-1) >= W){
                t = 0;
            }
            else{
                t = buffer[i+2][j-1] * yfive[21];
            }
            if((i+2) < 0 || (i+2) >= H || (j) < 0 || (j) >= W){
                q = 0;
            }
            else{
                q = buffer[i+2][j] * yfive[22];
            }
            if((i+2) < 0 || (i+2) >= H || (j+1) < 0 || (j+1) >= W){
                r = 0;
            }
            else{
                r = buffer[i+2][j+1] * yfive[23];
            }
            if((i+2) < 0 || (i+2) >= H || (j+2) < 0 || (j+2) >= W){
                s = 0;
            }
            else{
                s = buffer[i+2][j+2] * yfive[24];
            }

            sum = (ptl + pu + ptopr + pl + p + pr + pbl + pd + pbr + a + b + c + d + e + f + g + h + l + m + n + o + t + q + r + s) / 60 + 128;
            
            //these are operations performed on each image when looping through pixel by pixel
            outimg[i][j] = sum;
            //printf("%x %x\n", outimage[i][j],buffer[i][j]);
        }
    }
    }
    //after ifs
    //manually change output to filter choice raw
    FILE * fp2 = fopen("beach5Vout.raw", "wb");

    fwrite(outimg, H*W, 1, fp2);

    fclose(fp);
    fclose(fp2);
    return;
}

int main(){
    //height and width of all images
    int imgH = 500;
    int imgW = 750;

    /*Last arg is filter choice
    0 - 3 Horizontal filter
    1 - 3 Vertical filter
    2 - 5 Horizontal filter
    3 - 5 Vertical filter
    */
    ip(imgH, imgW, 3);
    //2D array of 0s Buffer is used to hold data from file pointer
    //Sobel Operators for difference operations
    //Convolve with 3*3 H/V & 5*5 H/V for 3 images = 12 images
    //first image
    
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

    if(sum > 255){
                printf("In Y3 sum is %d", sum);
                sum = 255;
            }
            else if (sum < 0)
            {
                sum = 0;
            }
            else{
                sum = sum;
            }

    checking buffers
    */
