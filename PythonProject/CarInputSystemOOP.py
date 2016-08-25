class Vehicle():
    def __init__(self, make, model,year,mile,price):
        self.make = make
        self.model = model
        self.yr = year
        self.mile = mile
        self.price = price

    def __getMake__(self):
        return self.make
    def __getModel__(self):
        return self.model
    def __getYear__(self):
        return self.yr
    def __getMile__(self):
        return self.mil
    def __getPrice__(self):
        return self.price

    def __setMake(self,m):
        self.make = m
    def __setModel(self,m):
        self.model = m
    def __setYear(self,y):
        self.yr = y
    def __setMile(self,m):
        self.mile = m
    def __setPrice(self,p):
        self.price = p

    def Display(self):
        print("Make: " + self.make)
        print("Year: " + str(self.yr))
        print("Model: " + self.model)
        print("Miles: " + str(self.mile))
        print("Price: " + str(self.price))
        
class Car(Vehicle):
    def __init__(self,make,model,year,mile,price,numDoor):
        super().__init__(make,model,year,mile,price)
        self.numDoor = numDoor
    def getDoor(self):
        return self.numDoor
    def setDoor(self,num):
        self.numDoor = num
    def Display(self):
        print("Inventory unit: Car")
        super().Display()
        print("Number of doors: " + str(self.numDoor))
        
class Truck(Vehicle):
    def __init__(self,make,model,year,mile,price,numDrive):
        super().__init__(make,model,year,mile,price)
        self.DriveType = numDrive
    def getDriveType(self):
        return self.DriveType
    def setDriveType(self,num):
        self.DriveType = num
    def Display(self):
        print("Inventory unit: Truck")
        super().Display()
        print("Drive Type: " + str(self.DriveType))
        
class SUV(Vehicle):
    def __init__(self,make,model,year,mile,price,num):
        super().__init__(make,model,year,mile,price)
        self.Pas = num
    def getPas(self):
        return self.Pas
    def setPas(self,num):
        self.Pas = num
    def Display(self):
        print("Inventory unit: SUV")
        super().Display()
        print("Passenger Capacity " + str(self.Pas))
        
class Inventory:
    def __init__(self):
        self.lst = []
    def addVehicle(self, ve):
        self.lst.append(ve)
    def Display(self):
        for vehi in self.lst:
            vehi.Display()
            print("\n")

def main():
    vehiList = Inventory()
    t = input("Enter your vehicle type -Car, Truck or SUV- Type DONE to finish: ")
    while t != "DONE":
        while t.lower() != "car" and t.lower() != "truck" and t.upper() != "SUV":
            t = input("Please only enter Car, Truck or SUV: ")
        make = input("Enter vehicle manufacturer: ")
        year = input("Enter year of vehicle: ")
        model = input("Enter model: ")
        mile = input("Enter mile: ")
        price = input("Enter price: ")

        if t.lower() == 'car':
            numDoor = input("Enter number of doors:")
            while numDoor != '2' and numDoor != '4':
                numDoor = input("Please re-enter the number of doors. Only 2 doors or 4 doors: ")
            vehiList.addVehicle(Car(make,year,model,mile,price,numDoor))
            
        elif t.lower() == 'truck':
            dr = input("Enter drive type: ")
            while dr != '2' or dr != '4':
                dr = input("Please re-enter the drive type. Only 2 or 4 wheels: ")
            vehiList.addVehicle(Truck(make,year,model,mile,price,dr))
        elif t.upper() == 'SUV':
            pas = input("Enter number of passenger: ")
            vehiList.addVehicle(SUV(make,year,model,mile,price,pas))
        print("\n")
        t = input("You just finished adding a vehicle to inventory list. Enter your next vehicle type or DONE to finish: ")
    print("\n")
    vehiList.Display()    
main()
