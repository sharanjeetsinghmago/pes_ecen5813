/*
 * logger.c
 *
 *  Created on: Dec 8, 2017
 *      Author: vipul
 */



#include "logger.h"
#include "circbuf.h"
#include "conversion.h"
#include "uart.h"
#include "rtc.h"

extern CB_t logger_buff;

uint8_t log_count=0;

extern bool log_flag;


void log_data(uint8_t * ptr, uint8_t len)
{
	uint8_t i=0;
	while(i<len)
	{
		CB_buffer_add_item(&logger_buff, *(ptr+i));
		UART_send(ptr+i);
		i++;
	}

}

void log_string(char * str)
{
	uint32_t i=0;
	while(*(str+i) != '\0')
	{
		CB_buffer_add_item(&logger_buff, *(str+i));
		i++;
	}
}


void log_integer(uint32_t x)
{
	uint8_t l,i;
	uint8_t * y;

	y = (uint8_t *)malloc(4);

	l = my_itoa(x, y, 10);

	for(i = 0; i < l; i++)
	{
		CB_buffer_add_item(&logger_buff, *(y+i));
	}

}

void log_flush()
{
	size_t len, i;
	uint8_t data;

	len = logger_buff.count;

	for(i = 0; i < len; i++)
	{
		CB_buffer_remove_item(&logger_buff, &data);
		UART_send(&data);
	}

	log_flag = false;
	log_count = 0;
}



void log_item(Log_type * data, CB_t * buffer)
{
	char time_str[] = "\n\r";
	char nline[] = "\n\r";
	char tab[] = "\t";
	uint8_t checksum;


	if(data->logID == LOGGER_INITIALIZED)
	{
		char id[] = "\tLOGGER_INITIALIZED";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == GPIO_INITIALIZED)
	{
		uint8_t id[] = "\tGPIO_INITIALIZED";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == SYSTEM_INITIALIZED)
	{
		uint8_t id[] = "\tSYSTEM_INITIALIZED";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == SYSTEM_HALTED)
	{
		uint8_t id[] = "\tSYSTEM_HALTED";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == INFO)
	{
		uint8_t id[] = "\tINFO : ";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
	}
	else if(data->logID == WARNING)
	{
		uint8_t id[] = "\tWARNING : ";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
	}
	else if(data->logID == ERROR)
	{
		uint8_t id[] = "\tERROR";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
	}
	else if(data->logID == PROFILING_STARTED)
	{
		uint8_t id[] = "\tPROFILING_STARTED";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == PROFILING_RESULT)
	{
		uint8_t id[] = "\tPROFILING_RESULT";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == PROFILING_COMPLETED)
	{
		uint8_t id[] = "\rPROFILING_COMPLETED";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == DATA_RECEIVED)
	{
		char id[] = "\tDATA_RECEIVED";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == DATA_ANALYSIS_STARTED)
	{
		char id[] = "\tDATA_ANALYSIS_STARTED";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == DATA_ALPHA_COUNT)
	{
		char id[] = "\tDATA_ALPHA_COUNT : ";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		log_string(tab);
		log_integer(data->val);
		checksum = data->logID ^ data->log_time ^ data->val;
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == DATA_NUMERIC_COUNT)
	{
		char id[] = "\tDATA_NUMERIC_COUNT : ";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		log_string(tab);
		log_integer(data->val);
		checksum = data->logID ^ data->log_time ^ data->val;
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == DATA_PUNCTUATION_COUNT)
	{
		char id[] = "\tDATA_PUNCTUATION_COUNT : ";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		log_integer(data->val);
		checksum = data->logID ^ data->log_time ^ data->val;
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == DATA_MISC_COUNT)
	{
		char id[] = "\tDATA_MISC_COUNT : ";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		log_string(tab);
		log_integer(data->val);
		checksum = data->logID ^ data->log_time ^ data->val;
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == DATA_ANALYSIS_COMPLETED)
	{
		char id[] = "\tDATA_ANALYSIS_COMPLETED";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}
	else if(data->logID == HEARTBEAT)
	{
		uint8_t id[] = "\tHEARTBEAT ";
		log_string(time_str);
		log_integer(data->log_time);
		log_string(id);
		checksum = data->logID ^ data->log_time ;
		log_string(tab);
		log_string(tab);
		log_string(tab);
		log_integer(checksum);
	}

	log_count++;

	if(log_count >= 20)
	{
		log_flag = true;

	}

}
