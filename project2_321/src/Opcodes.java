/*
Daniel Hargrave
dh11
 */

//This class basically just it to help match names, opcodes, and types.
//The table is just what we were given
public class Opcodes {
    //Keeps track of the instruction name
    public String name;
    //keeps track of the instruction opcode
    public int opcode;
    //keeps track of the instruction type
    public String type;

    public Opcodes(String name, int opcode, String type) {
        this.name = name;
        this.opcode = opcode;
        this.type = type;
    }

    //This is all from the table that we were provided
    public static final Opcodes[] opcodeTable = {
            new Opcodes("ADD", 0b10001011000, "R"),
            new Opcodes("ADDI", 0b1001000100, "I"),
            new Opcodes("ADDIS", 0b1011000100, "I"),
            new Opcodes("ADDS", 0b10101011000, "R"),
            new Opcodes("AND", 0b10001010000, "R"),
            new Opcodes("ANDI", 0b1001001000, "I"),
            new Opcodes("ANDIS", 0b1111001000, "I"),
            new Opcodes("ANDS", 0b1110101000, "R"),
            new Opcodes("B", 0b000101, "B"),
            new Opcodes("B.cond", 0b01010100, "CB"),
            new Opcodes("BL", 0b100101, "B"),
            new Opcodes("BR", 0b11010110000, "R"),
            new Opcodes("CBNZ", 0b10110101, "CB"),
            new Opcodes("CBZ", 0b10110100, "CB"),
            new Opcodes("DUMP", 0b11111111110, "R"),
            new Opcodes("EOR", 0b11001010000, "R"),
            new Opcodes("EORI", 0b1101001000, "I"),
            new Opcodes("FADDD", 0b00011110011, "R"),
            new Opcodes("FADDS", 0b00011110001, "R"),
            new Opcodes("FCMPD", 0b00011110011, "R"),
            new Opcodes("FCMPS", 0b00011110001, "R"),
            new Opcodes("FDIVD", 0b00011110011, "R"),
            new Opcodes("FDIVS", 0b00011110001, "R"),
            new Opcodes("FMULD", 0b00011110011, "R"),
            new Opcodes("FMULS", 0b00011110001, "R"),
            new Opcodes("FSUBD", 0b00011110011, "R"),
            new Opcodes("FSUBS", 0b00011110001, "R"),
            new Opcodes("HALT", 0b11111111111, "R"),
            new Opcodes("LDUR", 0b11111000010, "D"),
            new Opcodes("LDURB", 0b00111000010, "D"),
            new Opcodes("LDURD", 0b11111100010, "D"),
            new Opcodes("LDURH", 0b01111000010, "D"),
            new Opcodes("LDURS", 0b10111100010, "D"),
            new Opcodes("LDURSW", 0b10111000100, "D"),
            new Opcodes("LSL", 0b11010011011, "R"),
            new Opcodes("LSR", 0b11010011010, "R"),
            new Opcodes("MUL", 0b10011011000, "R"),
            new Opcodes("ORR", 0b10101010000, "R"),
            new Opcodes("ORRI", 0b1011001000, "I"),
            new Opcodes("PRNL", 0b11111111100, "R"),
            new Opcodes("PRNT", 0b11111111101, "R"),
            new Opcodes("SDIV", 0b10011010110, "R"),
            new Opcodes("SMULH", 0b10011011010, "R"),
            new Opcodes("STUR", 0b11111000000, "D"),
            new Opcodes("STURB", 0b00111000000, "D"),
            new Opcodes("STURD", 0b11111100000, "D"),
            new Opcodes("STURH", 0b01111000000, "D"),
            new Opcodes("STURS", 0b10111100000, "D"),
            new Opcodes("STURSW", 0b10111000000, "D"),
            new Opcodes("SUB", 0b11001011000, "R"),
            new Opcodes("SUBI", 0b1101000100, "I"),
            new Opcodes("SUBIS", 0b1111000100, "I"),
            new Opcodes("SUBS", 0b11101011000, "R"),
            new Opcodes("UDIV", 0b10011010110, "R"),
            new Opcodes("UMULH", 0b10011011110, "R")
    };
}
