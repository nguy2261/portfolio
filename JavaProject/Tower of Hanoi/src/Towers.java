//This program solves the game tower of Hanoi by doing it recursively.
//More information can be found at: https://en.wikipedia.org/wiki/Tower_of_Hanoi
public class Towers {
		
			private int count = 1;
			private int n;
			
			public Towers(int value){ //The constructor: the value is the number of disks needed to move
				n = value;
			}
			
			public void solve(int start, int destination){ //
				
				if (start == 1 && destination == 3){
					int TargetDisk = destination;
					int CurrentDisk = start;
					int MovingDisk = 2;
					move(n, TargetDisk, CurrentDisk, MovingDisk);
				}
				else if(start == 2 && destination == 3){
					int TargetDisk = destination;
					int CurrentDisk = start;
					int MovingDisk = 1;
					move(n, TargetDisk, CurrentDisk, MovingDisk);
				}
				else if(start == 1 && destination == 2){
					int TargetDisk = destination;
					int CurrentDisk = start;
					int MovingDisk = 3;
					move(n, TargetDisk, CurrentDisk, MovingDisk);
				}
				else if(start == 2 && destination == 1){
					int TargetDisk = destination;
					int CurrentDisk = start;
					int MovingDisk = 3;
					move(n, TargetDisk, CurrentDisk, MovingDisk);
				}
				else if(start == 3 && destination == 1){
					int TargetDisk = destination;
					int CurrentDisk = start;
					int MovingDisk = 2;
					move(n, TargetDisk, CurrentDisk, MovingDisk);
				}
				else if(start == 3 && destination == 2){
					int TargetDisk = destination;
					int CurrentDisk = start;
					int MovingDisk = 1;
					move(n, TargetDisk, CurrentDisk, MovingDisk);
				}
				else if (start == destination){
					System.out.println("No moves necessary");
				}
				else{
					System.out.println("Start/Destination is not valid");
				}
			}
			
			
			
			private void move(int n, int target, int current, int moving){ //Recursion to move the disc
				if (n == 1) {
					MoveOne(1,current, target); //This move only the top disc
				}
				else if ( n <= 0){
					System.out.println("You enter invalid number of disc");
				}
				else{
					move(n-1, moving, current, target); //Move the n-1 discs to the moving disc
					MoveOne(n, current, target);
					move(n-1, target, moving, current); //Move the n-1 discs to target disc
				}
			} 
			
			
			public void MoveOne(int DiscNum, int Start, int End){ //Move the n-th 
				System.out.println("Step-" + count+ ": Moving disc " + DiscNum + " from tower " + Start + " to tower " + End);
				count++;
			}
			
			public static void main(String[] args) {
				Towers TowerMain = new Towers(3); //Start the tower with 3 disk
				TowerMain.solve(1,3);            //Start moving 3 disks from tower 1 to tower 3
			}
			
	}

