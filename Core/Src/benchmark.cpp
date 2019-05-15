  //********BENCHMARK START*****//

    printf("Hello World!\n");

    long ITER = 500000;
    int ia,ib,ic,id,ie,ig,ih,ii;
     long int la, lb;
    long int lc,ld,le,lg,lh,li,N;
    long int runs=0;
     float fa,fb;
    float fc,fd,fe,fg,calib, fcalib;
     double da,db;
    double dc,dd,de,df,dg;
    long elapsed;

    ie = (SysTick->VAL % 2) + 1;
    fb = fa*fb;
    elapsed=__HAL_TIM_GET_COUNTER(&htim5);
      for (ic=ie; ic<(ie+ITER); ic++) //this syntax avoid compiler semplifications
      {
      	fa = fb;
      }
      elapsed=__HAL_TIM_GET_COUNTER(&htim5)-elapsed;
      fcalib=(float)elapsed;
        printf(" Time (ms)...= ");
        printf("%ld",HAL_GetTick());
        printf(" ms\n");
        printf(" INT_LOOP(ITER) bench...= ");


        printf("%ld", elapsed);
        printf(" microseconds");
        printf(" ");
        printf("%f",(float)ITER/(float)elapsed);
        printf("MIPS\n");



        la=(long)(SysTick->VAL % 2) + 1;
        lb=(long)(SysTick->VAL % 1000) + 1;
        fb=0;
        fg=0;
        le=(SysTick->VAL % 2) + 1;
        elapsed=__HAL_TIM_GET_COUNTER(&htim5);
        for (lc=le; lc<(le+ITER); lc++) //this syntax avoid compiler simplifications
        {
      	  la = lb;
        }
        elapsed=__HAL_TIM_GET_COUNTER(&htim5)-elapsed;
        calib=(float)elapsed;

        printf(" LONG_LOOP(ITER) bench...= ");

        printf("%ld",elapsed);
        printf(" microseconds");
        printf(" ");
        printf("%f",(float)ITER/(float)elapsed);
        printf("MIPS\n");

        la=(long)(SysTick->VAL % 2) + 1;
        lb=(long)(SysTick->VAL % 1000) + 1;
        fb=0;
        fg=0;
        le=(SysTick->VAL % 2) + 1;
        elapsed=__HAL_TIM_GET_COUNTER(&htim5);
        for (lc=le; lc<(le+ITER); lc++) //this syntax avoid compiler simplifications
        {
      	  lb = lb * la;
        }
        elapsed=__HAL_TIM_GET_COUNTER(&htim5)-elapsed;

        printf(" LONG_MUL(ITER) bench...= ");

        printf("%ld",elapsed);
        printf(" microseconds");
        printf(" ");
        printf("%f",(float)ITER/((float)elapsed-calib));
        printf("MIPS\n");

        la=(long)(SysTick->VAL % 2) + 1;
        lb=(long)(SysTick->VAL % 1000) + 1;
        fb=0;
        fg=0;
        le=(SysTick->VAL % 2) + 1;
        elapsed=__HAL_TIM_GET_COUNTER(&htim5);
        for (lc=le; lc<(le+ITER); lc++) //this syntax avoid compiler simplifications
        {
      	  lb = lb / la;
        }
        elapsed=__HAL_TIM_GET_COUNTER(&htim5)-elapsed;

        printf(" LONG_DIV(ITER) bench...= ");

        printf("%ld",elapsed);
        printf(" microseconds");
        printf(" ");
        printf("%f",(float)ITER/((float)elapsed-calib));
        printf("MIPS\n");



        fa=(float)(SysTick->VAL % 2) + 1;
        fb=(float)(SysTick->VAL % 1000) + 1;
        fb=0;
        fg=0;
        le=(SysTick->VAL % 2) + 1;
        elapsed=__HAL_TIM_GET_COUNTER(&htim5);
        for (lc=le; lc<(le+ITER); lc++)
        {
          fb=fb/fa;
        }
        elapsed=__HAL_TIM_GET_COUNTER(&htim5)-elapsed;

        printf(" FLOAT_DIV(ITER) bench...= ");

        printf("%ld",elapsed);
        printf(" microseconds");
        printf(" ");
        printf("%f",(float)ITER/((float)elapsed-fcalib));
        printf("MFLOPS\n");


        le=(SysTick->VAL % 2) + 1;
        da=(double)(SysTick->VAL % 2) + 1;
        db=(double)(SysTick->VAL % 1000) + 1;
        db=0;
        dg=0;
        elapsed=__HAL_TIM_GET_COUNTER(&htim5);
        for (lc=le; lc<(le+ITER); lc++)
        {
          db=db/da;
        }
         elapsed=__HAL_TIM_GET_COUNTER(&htim5)-elapsed;

         printf(" DOUBLE_DIV(ITER) bench...= ");

         printf("%ld",elapsed);
         printf(" microseconds");
         printf(" ");
         printf("%f",(float)ITER/((float)elapsed-fcalib));
         printf("MFLOPS\n");



        le=(SysTick->VAL % 2) + 1;
        elapsed=__HAL_TIM_GET_COUNTER(&htim5);
        for (lc=le; lc<(le+ITER); lc++)
        {
          fb=fb*fa;
        }

        elapsed=__HAL_TIM_GET_COUNTER(&htim5)-elapsed;
        printf(" FLOAT_MUL(ITER) bench...= ");

        printf("%ld",elapsed);
        printf(" microseconds");
        printf(" ");
        printf("%f",(float)ITER/((float)elapsed-fcalib));
        printf("MFLOPS\n");
        le=(SysTick->VAL % 2) + 1;
        elapsed=__HAL_TIM_GET_COUNTER(&htim5);
        for (lc=le; lc<(le+ITER); lc++)
        {
          db=db*da;
        }
         elapsed=__HAL_TIM_GET_COUNTER(&htim5)-elapsed;

         printf(" DOUBLE_MUL(ITER) bench...= ");

         printf("%ld",elapsed);
         printf(" microseconds");
         printf(" ");
         printf("%f",(float)ITER/((float)elapsed-fcalib));
         printf("MFLOPS\n");

         printf("-------------------------------------------\n");

  //*************END BENCHMARK**********************//
