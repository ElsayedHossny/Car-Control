#ifndef STDTYPES_H_
#define STDTYPES_H_


typedef unsigned char    u8;
typedef signed char    s8;

typedef  char    c8;

typedef unsigned short    u16;
typedef signed short    s16;

typedef unsigned long    u32;
typedef signed long     s32;


#define  MAX_u16     ((u16)65535)
#define  MIN_u16     ((u16)0)
#define  MAX_s16     ((s16)32767)
#define  MIN_s16     ((s16)-32768)


typedef enum{
	FALSE=0x55,
	TRUE=0xAA
}bool_t;


typedef enum{
	OK=0,
	NOK,
	NULL_PTR,
	OUT_OF_RANGE,
	BUSY,

}error_t;



#define  GET_BIT(reg,bit)    ( (reg>>bit) & 1 )
#define  SET_BIT(reg,bit)     (reg=(reg|(1<<bit)))
#define  CLR_BIT(reg,bit)     ( reg=(reg & (~(1<<bit))))
#define  Tog_BIT(reg,bit)    (reg = (reg ^ (1<<bit) ) )


#endif /* STDTYPES_H_ */