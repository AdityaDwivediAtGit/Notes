/*
Lecture 2: Verilog Ports, Data types and Assignments

Datatype:
    1. Net Types (physical connection between structural elements)
        Default Value: z (not connected)
        eg. wire
    2. Register Type (represent abstract storage element)
        Default Value: x (can be 0 or 1)
        eg. reg
*/
    //Scalars:    
        wire w1;
    //Vectors:
        wire [msb:lsb] wire1,wire2.......
        reg [msb:lsb] reg1,reg2.......
        Eg. wire [6:0] Clear;      //<-------- 7 bit wire

    //Array of 64 registers containing 4 bits each
        reg [0:3]     abc      [0:63] ;
        reg bits/reg  reg_name no_of_reg; //********************
    //Array of 5 registers of size 1 bit each
        reg abc      [0:4];
        reg reg_name no_of_reg;

    // Ports:
    //     1. input
    //     2. output
    //     3. inout

    //Event Control Elements: (usually used with sequential circuits)
    //    1. Edge Trigerred Control
            @(posedge clk) //positive(leading) edge of clock
            Curr_State=Next_state;
    //    2. level Trigerred Control
            @(A or B) //change in values of A or B
            Out = A & B;
    
    //Bubble at the clk input of flipflop represents that the flipflop is negative edge trigerred

    //&& represents Binary AND operation (Bitwise)
        Y = A && B;
    //& represents Unary AND operation (You have to and each bit of A with every bit of B) (used in DataFlow Modelling)
        Y = A & B;

    //Assignments (assign keyword)
    //  1. Continuous Assignments (deals with nets(Vectors and Scalars))
            assign out = in1 & in2;
            // Triggered whenever value at the right hand side change

    //  2. Procedural Assignments (Drives values onto registers (Vectors and Scalars))
        // follows sequence like C Programming
        // Keywords:
            always initial begin end 
        // Types of Procedural Assignments:
            // a. Blocking
            // b. Non Blocking
        // If there are multiple initial blocks, then all will be executed simultaneously at t=0
        // always Block VS initial Block
            // initial block (Executed only once at t=0)
                ...
                initial begin
                    Sum = 0;
                    Carry = 0;
                end
            // always block (Executes everytime A or B changes)
                always @(A or B)
                begin 
                    Sum = A ^ B;
                    Carry = A & B;
                end

        // Blocking VS Non-Blocking Assignments
            // Blocking (Executed in order they are listed)
                // uses "=" 
                initial begin 
                    a = 1;                  // executes at t = 0
                    b = 0;                  // executes at t = 0
                    c = 1;                  // executes at t = 0
                    #10 reg_1 = 1'b0;       // executes at t = 0 + 10 = 10, #10 represents delay of 10 units
                    #5      c = reg_1;      // executes at t = 10 + 5 = 15 (5 units delay)
                    #5  reg_2 = b;          // executes at t = 15 + 5 = 20 (5 units delay)
                end
            // Non-Blocking (Executed simultaneusly)
                // uses "<=" 
//Lec 2 (28:30)