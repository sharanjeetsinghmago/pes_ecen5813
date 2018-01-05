**************************************************************************
#project3 repository
**************************************************************************

Author: Vipul Gupta

Project: Project 3 - Logging, SPI, DMA & Profiling

Members: 1. Vipul Gupta (vipul.gupta@colorado.edu)

	 2. Sharanjeet Mago (sharanjeet.mago@colorado.edu)

Description: This project is based on a Binary logger application which uses UART and Circular buffer implementation. A logger enables one to report data to a PC, this helps to interpret what is happening with the embedded system. A heartbeat log (using Systick) is used to log the state of the system.

Functionality: It processes logs in the backgroung using Circular buffer data structure and after taking 20 elements from the terminal, gives a complete log report along with the heartbeat log (every second).

**************************************************************************
