/*
Daniel Hargrave
dh11
 */

//This class basically just keeps track of what bits are needed for an instruction
public class Instructions {

    //keeps track of the bits
    private int bits;
    //keeps track of the type
    private String type;
    //keeps track of the name of the instruction
    private String instruction;

    public Instructions(int bits, String type, String instruction) {
        this.bits = bits;
        this.type = type;
        this.instruction = instruction;
    }

    //This is the method that gets the bits from one point to another
    //This does all of the work when dealing with bits.
    public int getBits(int value, int high, int low) {
        int part = (1 << (high - low + 1)) - 1;
        return (value >>> low) & part;
    }

    //This makes it so signed numbers work for for D type, B type, and CB type
    public int signExtend(int value, int numberofBits) {
        int shift = 32 - numberofBits;
        return (value << shift) >> shift;
    }

    //returns the type
    public String getType() {
        return type;
    }

    //returns the instruction name
    public String getInstruction() {
        return instruction;
    }

    //sets the bits
    public void setBits(int bits) {
        this.bits = bits;
    }

    //sets the type
    public void setType(String type) {
        this.type = type;
    }

    //sets the instruction name
    public void setInstruction(String instruction) {
        this.instruction = instruction;
    }

    //gets the opcode
    public int getOpcode() {
        if (type.equals("R") || type.equals("D")) {
            return getBits(bits, 31, 21);
        }
        else if (type.equals("I")) {
            return getBits(bits, 31, 22);
        }
        else if (type.equals("B")) {
            return getBits(bits, 31, 26);
        }
        else if (type.equals("CB")) {
            return getBits(bits, 31, 24);
        }
        else {
            return -1;
        }
    }

    //gets Rd/Rt. Used for all but B types
    public int getRdOrRt() {
        return getBits(bits, 4, 0);
    }

    //gets Rn. Used of R, I, and D types
    public int getRn() {
        return getBits(bits, 9, 5);
    }

    //gets Rm. Used for R types
    public int getRm() {
        return getBits(bits, 20, 16);
    }

    //gets Shamt. Used for R types
    public int getShamt() {
        return getBits(bits, 15, 10);
    }

    //gets ALU_intermmediate. Used for I types
    public int getALU() {
        return getBits(bits, 21, 10);
    }

    //gets DT_address. Used for D type
    public int getDT() {
        return signExtend(getBits(bits, 20, 12), 9);
    }

    //gets Op. Used for D type
    public int getOp() {
        return getBits(bits, 11, 10);
    }

    //gets BR_address. Used for B type
    public int getBR_Add() {
        return signExtend(getBits(bits, 25, 0), 26);
    }

    //gets COND_BR_address. Used for CB type
    public int getCOND_BR_Add() {
        return signExtend(getBits(bits, 23, 5), 19);
    }

}
