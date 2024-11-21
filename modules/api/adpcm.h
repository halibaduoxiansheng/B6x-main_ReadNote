/*
** adpcm.h - include file for adpcm coder.
**
** Version 1.0, 7-Jul-92.
*/
 
#ifndef ADPCM_H
#define ADPCM_H
 
#ifdef __cplusplus
extern "C" {
#endif

/*音频压缩算法 状态记录*/
struct adpcm_state {
	short    valprev;    /* 编码或解码时上一个 输出值 */
	char    index;        /* 索引，指向 步长值 中的某个值 */
};

//len 是采样点的个数，不是字节大小
int adpcm_coder(short* indata, char* outdata, int len, struct adpcm_state* state);
int adpcm_decoder(char* indata, short* outdata, int len, struct adpcm_state* state);
int adpcm_decoder2(char* indata, short* outdata, int len, struct adpcm_state* state);

#ifdef __cplusplus
}  /* extern "C" */
#endif
 
#endif /* ADPCM_H*/
