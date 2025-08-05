#include <iostream>
using namespace std;

//Subsystems
class PowerSupply {
    public:
        void providePower() {
            cout << "Power supply: Providing power..." << endl;
        }
};

class CoolingSystem {
    public:
        void startFans() {
            cout << "Cooling Ssytem: Fans started..." << endl;
        }
};

class CPU {
    public:
        void initialize() {
            cout << "CPU: Intialization started..." << endl;
        }
};

class Memory {
public:
    void selfTest() {
        cout << "Memory: Self-test passed..." << endl;
    }
};

class HardDrive {
public:
    void spinUp() {
        cout << "Hard Drive: Spinning up..." << endl;
    }
};

class  BIOS {
    public:
        void boot(CPU& cpu, Memory& memory) {
            cout << "BIOS: Booting CPU and Memory checks..." <<endl;
            cpu.initialize();
            memory.selfTest();
        }
};

class OperatingSystem {
    public:
        void load() {
            cout << "Operating System: Loading into memory..." << endl;
        }
};

//Facade : middleman class
class ComputerFacade {
    private:
        PowerSupply powerSupply;
        CoolingSystem coolingSystem;
        CPU cpu;
        Memory memory;
        HardDrive hardDrive;
        BIOS bios;
        OperatingSystem os;

    public:
        void startComputer() {
             cout << "----- Starting Computer -----" << endl;
            powerSupply.providePower();
            coolingSystem.startFans();
            bios.boot(cpu, memory);
            hardDrive.spinUp();
            os.load();
            cout << "Computer Booted Successfully!" << endl;
        }
};

//client
int main() {
    ComputerFacade computer;
    computer.startComputer();

    return 0;
}