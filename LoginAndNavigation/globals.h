#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"


//--------------------------------------------------------------------
// Global Variables

#endif // _GLOBALS_H

void ErrorCode(char* transaction ){
	if(atoi(lr_eval_string("{checkpoint}")) >0){
		
			lr_end_transaction(transaction, LR_PASS);
	}
	else{
			lr_end_transaction(transaction, LR_FAIL);
	}
}
