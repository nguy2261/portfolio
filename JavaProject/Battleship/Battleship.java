import java.util.Random;
import java.util.Scanner;


public class Battleship {
	private String field[][] = new String[1][1];
	private String fieldMask[][] = new String[1][1];
	private int m = 3;
	private int n = 3;	
	private int shipHit = 0;
	//Constructor sets up the game and decides how many ships would be in the game
	public Battleship(int valuem, int valuen){
		m = valuem;
		n = valuen;
		int num = 0;
		if( m < 3 || n <3){
			System.out.println("m and n must be both at least 3 to set up the game");
		}
		else {
		field = new String[m][n];
		fieldMask = new String[m][n];
		for(int i = 0; i<m;i++){
			for(int j = 0; j < n;j++){
				field[i][j] = ".";
				fieldMask[i][j] = ".";
			}
		}
		
		if( m <= 0 || n <= 0)
			num = 0;
		else if(m < 20 || n < 20)
			num =1;
		else if (m >= 20 && n >= 20 && m < 30 && n < 30)
			num =2;
		else if (m >= 30 && n >= 30 && m < 40 && n < 40)
			num =3;
		else if (m >= 40 && n >= 40)
			num =4;
		
		shipHit = num*3;
		Ship(num);
		}
	}
	
	//Method to random the ship on the board game
	public void Ship(int numShip){
		int ShipPos[][]= new int[numShip][3];
		Random rnd = new Random();
		for(int y = 0; y < numShip; y++){
				ShipPos[y][0] = rnd.nextInt(m-2)+1;
				ShipPos[y][1] = rnd.nextInt(n-2)+1;
				ShipPos[y][2] = rnd.nextInt(2);
				
				while (check(ShipPos[y][0],ShipPos[y][1],ShipPos[y][2]) == -1){
					ShipPos[y][0] = rnd.nextInt(m-1)+1;
					ShipPos[y][1] = rnd.nextInt(n-1)+1;
					ShipPos[y][2] = rnd.nextInt(2);
				}
				
				if(ShipPos[y][2] == 0){
					field[ShipPos[y][0] - 1][ShipPos[y][1]] = "X";
					field[ShipPos[y][0]][ShipPos[y][1]] = "X";
					field[ShipPos[y][0] + 1][ShipPos[y][1]] = "X";
				}
				else{
					field[ShipPos[y][0]][ShipPos[y][1]-1] = "X";
					field[ShipPos[y][0]][ShipPos[y][1]] = "X";
					field[ShipPos[y][0]][ShipPos[y][1]+1] = "X";
				}
		}
	}
	
	
	
	//Method to decide horizontal or vertical arrangement on the board.
	public int check(int x, int y, int z){
		if (field[x][y-1] == "X" && field[x][y+1] == "X"){
			if (field[x-1][y] == "X" && field[x+1][y] == "X"){
				z = -1;
			}
			else 
				z = 1;
		}
		else if (field[x-1][y] == "X" && field[x+1][y] == "X"){
			z = 0;
		}
		return z;
	}
	
	
	//Method to input the coordinate for the user to shoot
	public void Hit(){
		int shoot = 0;
		int Row = -1;
		int Column = -1;
		Scanner input = new Scanner(System.in);
		
		while(shipHit > 0){  
	    System.out.print("Row: ");
	    Row = input.nextInt()-1;
	    
	    System.out.print("Column: ");
	    Column = input.nextInt()-1;
	    shoot++;
		if(Row < m && Column < n){
			
			if(field[Row][Column] == "X"){
				fieldMask[Row][Column] = "?";
				field[Row][Column] = "?";
				shipHit = shipHit - 1;
				System.out.println("Hit\n");
			}
			
			if(Row >= 1 && Column >=1 && Row <= m-2 && Column <= n -2){
				if (field[Row-1][Column+1] == "X"||field[Row-1][Column-1] == "X" || field[Row+1][Column-1] == "X"|| field[Row+1][Column+1] == "X" || field[Row+1][Column] == "X"||field[Row-1][Column] == "X"||field[Row][Column-1] == "X"||field[Row][Column+1] == "X"){
					System.out.println("A Miss, but Very Close\n");
					if (field[Row][Column] != "?"){
						field[Row][Column] = "O";
						fieldMask[Row][Column] = "O";
					}
				}
			}
			
			if(Row >= 2 && Column >=2&& Row <= m-3 && Column <= n -3){
				if (field[Row-2][Column+2] == "X"||field[Row-2][Column-2] == "X" || field[Row+2][Column-2] == "X"|| field[Row+2][Column+2] == "X" ||field[Row+2][Column] == "X"||field[Row-2][Column] == "X"||field[Row][Column-2] == "X"||field[Row][Column+2] == "X"){
					System.out.println("A Miss, but Close\n");
					if (field[Row][Column] != "?"){
						field[Row][Column] = "O";
						fieldMask[Row][Column] = "O";
					}
				}
			}
			
			if (field[Row][Column] != "?"){
				System.out.println("Miss!!\n");
				if(field[Row][Column] == "O"){
					System.out.println("You already shot this spot before (" + (Row+1) +","+(Column+1)+")");
				}
				field[Row][Column] = "O";
				fieldMask[Row][Column] = "O";
			}	
			
			Display();
			System.out.println("Number of ship position " + shipHit + "\nNumber of attempts: " + shoot);
		}
		else{
			System.out.println("You shoot to outside of the board. Please shoot again and this attempt didn't count");
			}
		}
		System.out.println("Number of ship " + shipHit + "\nNumber of attempts: " + shoot);
		System.out.println("Game over. You win the game. If you want to play again, please restart the program");
	}
	
	
	
	public void Display(){ //This method will display the board of the game
		String Result = "";
		String hori = "\t";
		for(int i = 0; i < n; i++){
			hori += (i+1) + "\t";
		}
		System.out.println(hori);
		for(int i = 0; i<m;i++){
			Result += (i+1) + "\t";
			for(int j = 0; j < n;j++){
				Result += fieldMask[i][j] + "\t";
			}
			System.out.println(Result);
			Result = "";
		}
	}
	
	public void DisplaySolution(){ //This method will display location of the ship
		String Result = "";
		String hori = "\t";
		for(int i = 0; i < n; i++){
			hori += (i+1) + "\t";
		}
		System.out.println(hori);
		for(int i = 0; i<m;i++){
			Result += (i+1) + "\t";
			for(int j = 0; j < n;j++){
				Result += field[i][j] + "\t";
			}
			System.out.println(Result);
			Result = "";
		}
	}
	
	public void Test(){ // Test method to check the location of the ship
		int count = 0;
		for (int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if (field[i][j] == "X")
					count ++;
			}
		}
		if (count == shipHit){
			System.out.println("The location of the ship is valid");
		}
		else
			System.out.println("The location of the ship is not valid");
	}
	
	public static void main(String[] args) {
		Battleship ABC = new Battleship(31,31);
		ABC.Display();
		ABC.Hit();
	}
}
