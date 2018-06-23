////////////////// flage.h : Defines the initialization flags for the DLL. ///////////////////////////////////////////////////////////////
struct kFlags
{
int n_back ;
int found;
int q_bit;

int f_bit ;
int s_bit ;
int p_bit ;

int g_bit ;
int c_bit ;
int o_bit ;

int x_bit ;
int so_bit ;
int b_bit;

int u_bit  ;
int ei_bit ;
int ipressed ;

int space_bit ;
int j_bit ;
int first_o ;

int derg_bit ;
int	derg_count ;
int spec_kgun ;

int spec_kgun_val;
int slash_bit ;
int i_flag ;

char previous_0 ;
char previous_1 ;
char previous_2 ;
char previous_3 ;

char last_consonant;
WPARAM lastglyph ;
int save_i;

int o_count ;

}kFlag = {
			-1,
			 0,
			 0,

			 0,
			 0,
			 0,
			 
			 0,
			 0,
			 0,
			 
			 0,
			 0,
			 0,
			 
			 0,
			 0,
			 0,
			 
			 0,
			 0,
			 0,
			 
			 1,
			 0 ,
			 0,
			 
			 0,
			 0,
			 0,

			 NULL,
			 NULL,
			 NULL,
			 
			 NULL,
			 NULL,
			 0,

			 0
	
};


void vClear_All_Flags()
{
				              kFlag.q_bit  = 0;
                              kFlag.f_bit = 0;
                              kFlag.s_bit = 0;
                              kFlag.p_bit = 0;
                              kFlag.g_bit = 0;
                              kFlag.c_bit = 0;
                              kFlag.o_bit = 0;
                              kFlag.x_bit = 0;
                              kFlag.so_bit = 0;
                              kFlag.b_bit = 0;
                              kFlag.u_bit  = 0;
                              kFlag.ei_bit = 0;
                              kFlag.ipressed = 0;
                              kFlag.space_bit = 0;
                              kFlag.j_bit = 0;
                              kFlag.first_o = 0;
//                              kFlag.derg_bit = 1;
//                              kFlag.derg_count ;
                              kFlag.spec_kgun = 0;
                              kFlag.spec_kgun_val;
                              kFlag.slash_bit = 0;
//                              ClearQueue();
		
}

	
