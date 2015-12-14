/***************************************************************************
 *                                                                         *
 *   IFDDRRSE.v - A dual edge triggered input flip-flop which emulates the *
 *     Xilinx primitive of the same name. Data is received on both         *
 *     positive and negative clock edges.                                  *
 *                                                                         *
 *   Copyright (C) 2007 by Patrick Suggate                                 *
 *   patrick@physics.otago.ac.nz                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
// TODO: Implement parameterizable delays.
//`timescale 1ns/100ps
module IFDDRRSE (
C0,
C1,
CE,
D,
R,
S,
Q0,
Q1
);
 
parameter INIT= 2'b00;
parameter DELAY= 2.0;
 
input C0;// Clock 0
input C1;
input CE;// Clock enable
 
input D;// Data valid on both edges
 
input R;// Reset
input S;
 
output Q0;// Posedge data
output Q1;
 
reg Q0= INIT [0];
reg Q1= INIT [1];

`ifdef __iverilog
always @(posedge C0)
if (R)Q0<= #DELAY 0;
else if (S)Q0<= #DELAY 1;
else if (CE)Q0<= #DELAY D;
 
always @(posedge C1)
if (R)Q1<= #DELAY 0;
else if (S)Q1<= #DELAY 1;
else if (CE)Q1<= #DELAY D;

`else
always @(posedge C0)
if (R)Q0<=  0;
else if (S)Q0<=  1;
else if (CE)Q0<=  D;
 
always @(posedge C1)
if (R)Q1<=  0;
else if (S)Q1<=  1;
else if (CE)Q1<=  D;

`endif
endmodule// IFDDRRSE

/***************************************************************************
 *                                                                         *
 *   OFDDRRSE.v - A dual edge triggered output flip-flop which emulates    *
 *     the Xilinx primitive of the same name. Data is output on both       *
 *     positive and negative clock edges. Uses include data transfers to   *
 *     DDR-SDRAMs.                                                         *
 *                                                                         *
 *   Copyright (C) 2007 by Patrick Suggate                                 *
 *   patrick@physics.otago.ac.nz                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
// TODO: Implement parameterizable delays.
`timescale 1ns/100ps
module OFDDRRSE (
	C0,
	C1,
	CE,
	D0,
	D1,
	Q,
	R,
	S
);
 
	parameter INIT= 1'b0;
	parameter DELAY= 0.0;
 
	input C0;// Clock 0
	input C1;
	input CE;// Clock enable
 
	input D0;// Data after a posedge
	input D1;
 
	input R;// Reset
	input S;
 
	output Q;// DDR output

	reg Q= INIT;
`ifdef __iverilog
 	always @(posedge C0 or posedge C1)
	begin
		if (R)
			Q<= #DELAY 0;
		else if (S)
			Q<= #DELAY 1;
		else
	begin
		if (C0)
			Q<= #DELAY D0;
		else
			Q<= #DELAY D1;
		end
	end
`else
 always @(posedge C0 or posedge C1)
begin
	if (R)
		Q<=  0;
	else if (S)
		Q		<=  1;
	else
	begin
		if (C0)
			Q<=  D0;
		else
			Q<=  D1;
		end
	end
`endif
endmodule// OFDDRRSE


/***************************************************************************
 *                                                                         *
 *   OFDDRTRSE.v - A dual edge triggered output flip-flop, with a tri-     *
 *     state output, which emulates the Xilinx primitive of the same name. *
 *     Data is output on both positive and negative clock edges. Uses      *
 *     include data transfers to DDR-SDRAMs.                               *
 *                                                                         *
 *   Copyright (C) 2007 by Patrick Suggate                                 *
 *   patrick@physics.otago.ac.nz                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
 // TODO: Finish parameterizable delays.
`timescale 1ns/100ps
module OFDDRTRSE #(
	parameter INIT= 1'b0,
	parameter ODELAY= 7.0,
	parameter ZDELAY= 1.0
) (
	input C0,
	input C1,
	input CE,
	input D0,// Data after a posedge
	input D1,
	input T,
	output O,// DDR output
	input R,
	input S
);
 
	reg O_r= INIT;
`ifdef __iverilog 
	assign #ZDELAY O= T ? 'bz : O_r ;
 
	always @(posedge C0 or posedge C1)
		if (CE) begin
		if (R) O_r<= #ODELAY 0;
		else if (S) O_r<= #ODELAY 1;
		else if (C0) O_r<= #ODELAY D0;
		else O_r<= #ODELAY D1;
	end
`else
	assign  O= T ? 'bz : O_r ;
 
	always @(posedge C0 or posedge C1)
		if (CE) begin
			if (R) O_r<=  0;
			else if (S) O_r<=  1;
			else if (C0) O_r<=  D0;
		else O_r<=  D1;
	end
`endif
endmodule// OFDDRTRSE
