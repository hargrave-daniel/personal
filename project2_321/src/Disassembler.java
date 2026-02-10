/*
Daniel Hargrave
dh11
 */
import java.io.*;
import java.util.ArrayList;
import java.util.List;

//This is the class that will actually disassemble the code
public class Disassembler {
    //keeps track of the list of instructions
    private List<Instructions> instructions;

    public Disassembler() {
        instructions = new ArrayList<Instructions>();
    }

    //This is the method that will actually read the binary from the file
    public void loadBinary(String filename) throws FileNotFoundException {
        File file = new File(filename);

        if (!file.exists()) {
            throw new FileNotFoundException(filename + " not found");
        }

        //Checks to make sure that the file has a number of bits that are a multiple of 4
        //This shouldn't matter unless the file given was not valid
        if (file.length() % 4 != 0) {
            throw new IllegalArgumentException(filename + " has incorrect bit amount");
        }

        try (DataInputStream in = new DataInputStream(new FileInputStream(file))) {
            //This takes in the 32 bits for each instruction and adds it to the list
            while (in.available() >= 4) {
                int bits = in.readInt();
                Instructions instruction = new Instructions(bits, "", "");
                instructions.add(instruction);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    //This is the method that actually takes in the bits for an instruction and uses the opcode table to match it up
    public void disassemble() {
        for (Instructions instruction : instructions) {
            boolean found = false;

            for(Opcodes op : Opcodes.opcodeTable) {
                instruction.setType(op.type);
                if (instruction.getOpcode() == op.opcode) {
                    found = true;
                    instruction.setInstruction(op.name);
                    break;
                }
            }
            //Shouldn't happen once again unless the file has incorrect values
            if (!found) {
                instruction.setInstruction("Unknown");
            }
        }
    }

    //This is the one that will format the instruction based on the operand
    private String format(Instructions instruction) {
        String name = instruction.getInstruction();

        //This is for the R types
        if (instruction.getType().equals("R")) {
            if(name.equals("PRNL") || name.equals("DUMP") || name.equals("HALT")) {
                return "";
            }
            else if(name.equals("PRNT")) {
                return "X" + instruction.getRdOrRt();
            }
            else if((name.equals("LSL") || name.equals("LSR"))) {
                return "X" + instruction.getRdOrRt() + ", X" + instruction.getRn() + ", #" + instruction.getShamt();
            }
            else if(name.equals("BR")) {
                return "X" + instruction.getRn();
            }
            else {
                return "X" + instruction.getRdOrRt() + ", X" + instruction.getRn() + ", X" + instruction.getRm();
            }
        }
        //This is for the I types
        else if (instruction.getType().equals("I")) {
            return "X" + instruction.getRdOrRt() + ", X" + instruction.getRn() + ", #" + instruction.getALU();
        }
        //This is for the D types
        else if (instruction.getType().equals("D")) {
            return "X" + instruction.getRdOrRt() + ", [X" + instruction.getRn() + ", #" + instruction.getDT() + "]";
        }
        //This is for the B types
        else if (instruction.getType().equals("B")) {
            return "label" + instruction.getBR_Add();
        }
        //This is for the CB types
        else if (instruction.getType().equals("CB")) {
            if(name.equals("B.cond")) {
                int code = instruction.getRdOrRt();
                String resultingcode;
                //This is based on the stuff in the documentation
                if(code == 0) {
                    resultingcode = "EQ";
                }
                else if(code == 1) {
                    resultingcode = "NE";
                }
                else if(code == 2) {
                    resultingcode = "HS";
                }
                else if(code == 3) {
                    resultingcode = "LO";
                }
                else if(code == 4) {
                    resultingcode = "MI";
                }
                else if(code == 5) {
                    resultingcode = "PL";
                }
                else if(code == 6) {
                    resultingcode = "VS";
                }
                else if(code == 7) {
                    resultingcode = "VC";
                }
                else if(code == 8) {
                    resultingcode = "HI";
                }
                else if(code == 9) {
                    resultingcode = "LS";
                }
                else if(code == 10) {
                    resultingcode = "GE";
                }
                else if(code == 11) {
                    resultingcode = "LT";
                }
                else if(code == 12) {
                    resultingcode = "GT";
                }
                else if(code == 13) {
                    resultingcode = "LE";
                }
                else {
                    resultingcode = "Error";
                }
                return "B." + resultingcode + " label" + instruction.getCOND_BR_Add();
            }
            else {
                return "X" + instruction.getRdOrRt() + ", label" + instruction.getCOND_BR_Add();
            }

        }
        else {
            return "Error";
        }
    }

    //This prints all of the instructions
    public void printSolution() {
        for (Instructions instruction : instructions) {
            String format = format(instruction);
            if(instruction.getInstruction().equals("B.cond")) {
                System.out.println(format);
            }
            else {
                System.out.println(instruction.getInstruction() + (format.isEmpty() ? "" : " " + format));
            }
        }
    }

    //Obviously the main method that uses all of the other methods
    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("Error");
            return;
        }

        Disassembler disassembler = new Disassembler();
        try {
            disassembler.loadBinary(args[0]);
            disassembler.disassemble();
            disassembler.printSolution();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
