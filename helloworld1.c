// helloworld.c
#define false 0;
#define true 1;
int main(void)
{

	volatile int * led = (int *) 0xFF200040; // red LED address
	volatile int * switchptr = (int *) 0xFF200030; // SW slider switch address
	volatile int * hex30 = (int *) 0xFF200020; // HEX3-0 address
	volatile int * hex54 = (int *) 0xFF200010; // HEX5-4 address
	volatile int * pb = (int *) 0xFF200000; // Push button address
	int switch_value;
	int btn_value;
	int wait = 99999;
	int h = 0b1110110;
	int e = 0b1111001;
	int l = 0b0111000;
	int o = 0b0111111;
	int u = 0b0111110;
	int r = 0b1010000;
	int d = 0b1011110;
	int sp = 0;
	
	int pushed = false;
	int hello = true;
	int pause = false;

	int sw6_0, sw9_7;

	int hw[24] = {sp, sp, sp, sp, sp, sp, h, e, l, l, o, sp, u, u, o, r, l, d, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp,};
	int n;
	int i; 
	int j;

	int ds[14] = {sp,sp,sp,sp,sp,sp,sp,sp,sp,sp,sp,sp,sp,sp}; //dynamic scroll
	while (1)
	{
		switch_value = *(switchptr); // check switches
		btn_value = (*pb); // check button
		*(led) = switch_value;
		ds[6] = switch_value % 128;
		ds[5] = switch_value / 128;

		if(hello)
		{
			for (i = 0; i < 18; i++)
			{
				*(hex54) = (hw[i]*256)+hw[i+1];
				*(hex30) = (hw[i+2]*256*256*256)+(hw[i+3]*256*256)+(hw[i+4]*256)+(hw[i+5]);
				for (n = 0; n < wait; n++)
				{
					btn_value = (*pb);
					if (btn_value == 0b0001)
					{
						hello = false;
					} // if end
					if (btn_value == 0b0010)
					{
						if (pause == 0)
						{
							pause = 1;
						}
						else
						{
							pause = 0;
						}
						for (j = 0; j < 999999; j++) // wait until button is no longer pressed
						{
						} // for end
					}
					if (btn_value == 0b0100)
					{
						wait = wait + 30000;
						for (j = 0; j < 499999; j++) // wait until button is no longer pressed
						{
						} // for end
					}
					if (btn_value == 0b1000)
					{
						wait = wait - 30000;
						for (j = 0; j < 499999; j++) // wait until button is no longer pressed
						{
						} // for end					
					}
					if (pause == 1)
					{
						n = 0;
					}
				} // for n end
				if(!hello)
				{
					break;
				}		
			} // for i end
		} // end if
		else
		{
			for (i = 0; i < 8; i++)
			{
				*(hex54) = (ds[i]*256)+ds[i+1];
				*(hex30) = (ds[i+2]*256*256*256)+(ds[i+3]*256*256)+(ds[i+4]*256)+(ds[i+5]);
				for (n = 0; n < wait; n++)
				{
					btn_value = (*pb);
					if (btn_value == 0b0001)
						hello = true;
					if (btn_value == 0b0010)
					{
						if (pause == 0)
							pause = 1;
						else
							pause = 0;
						for (j = 0; j < 999999; j++) // wait until button is no longer pressed
						{
						} // for end
					}
					if (btn_value == 0b0100)
					{
						wait = wait + 30000;
						for (j = 0; j < 499999; j++) // wait until button is no longer pressed
						{
						} // for end					
					}
					if (btn_value == 0b1000)
					{
						wait = wait - 30000;
						for (j = 0; j < 499999; j++) // wait until button is no longer pressed
						{
						} // for end
					}
					if (pause == 1)
						n = 0;

				} // for n end		
				if(hello)
				{
					break;
				}
			} // for i end

		} // end else

	} // while 1 end

} // main end
