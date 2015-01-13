// helloworld.c
int main(void)
{

	volatile int * led = (int *) 0xFF200040; // red LED address
	volatile int * switchptr = (int *) 0xFF200030; // SW slider switch address
	volatile int * hex30 = (int *) 0xFF200020; // HEX3-0 address
	volatile int * hex54 = (int *) 0xFF200010; // HEX5-4 address
	volatile int * pb = (int *) 0xFF200000; // Push button address
	int switch_value;
	int btn_value;
	int wait = 999999;
	int h = 0b1110110;
	int e = 0b1111001;
	int l = 0b0111000;
	int o = 0b0111111;
	int u = 0b0111110;
	int r = 0b1010000;
	int d = 0b1011110;
	int sp = 0;
	bool pushed = false;
	bool hello = true;

	int sw6_0, sw9_7;

	int hw[24] = {sp, sp, sp, sp, sp, sp, h, e, l, l, o, sp, u, u, o, r, l, d, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp, sp,};
	int n;
	int i; 

	int ds[14] = {sp,sp,sp,sp,sp,sp,sp,sp,sp,sp,sp,sp,sp,sp}; //dynamic scroll
	while (1)
	{
		switch_value = *(switchptr);
		btn_value = (*pb);
		*(led) = switch_value;
		ds[8] = switch_value % 128;
		ds[7] = switch_value / 128;

		if(hello)
		{
		for (i = 0; i < 18; i++)
		{
			*(hex54) = (hw[i]*256)+hw[i+1];
			*(hex30) = (hw[i+2]*256*256*256)+(hw[i+3]*256*256)+(hw[i+4]*256)+(hw[i+5]);
			if(btn_value)
			{
			for (n = 0; n < wait; n++)
			{
			} // for n end
			if(pushed)
			{
				break;
			}		
		} // for i end
		}
		else
		{
		for (i = 0; i < 8; i++)
		{
			*(hex54) = (ds[i]*256)+ds[i+1];
			*(hex30) = (ds[i+2]*256*256*256)+(ds[i+3]*256*256)+(ds[i+4]*256)+(ds[i+5]);
			if(btn_value)
			{
				pushed = true;
			}
			for (n = 0; n < wait; n++)
			{
			} // for n end		
			if(pushed)
			{
				break;
			}
		} // for i end

		}

		
	} // while 1 end
} // main end

/* ds[14] = {0,0,0,0,0,one,two,0,0,0,0,0}
two = switch1 + switch2 + switch3 + ...
one = switch9 + switch8 + switch7

0b0000000001
0b1000000000
0b0000000010*/
