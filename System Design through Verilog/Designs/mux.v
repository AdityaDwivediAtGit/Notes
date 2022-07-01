// 2:1 Multiplexer
//`timescale 1ns / 1ps
module mux(y,select_line,a,b);
    input select_line,a,b;
    output y;
    assign y = (select_line) ? a : b;
endmodule
