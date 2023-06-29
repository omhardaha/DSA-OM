class Solution {
    public boolean isPossibleToCutPath(int[][] board) {
        int column = board[0].length;
        int row = board.length;
        
        boolean[][] visited = new boolean[row][column];
        visited[0][0] = true;

        for (int index = 0; index < row; index++) {
            for (int jthIndex = 0; jthIndex < column; jthIndex++) {
                if (index == 0 && jthIndex == 0) continue;
                visited[index][jthIndex] = board[index][jthIndex] == 1 ?
                    ((index > 0 ? visited[index - 1][jthIndex] : false) || (jthIndex > 0 ? visited[index][jthIndex - 1] : false)) :
                    false;
            }
        }
        if (!visited[row - 1][column - 1]) return true;
        
        Queue < int[] > QueQ = new LinkedList<>();
        QueQ.add(new int[] {0,0});
        visited = new boolean[row][column];

        
        visited[0][0] = true;
        
        while (!QueQ.isEmpty()) {


            if (QueQ.size() == 1 && !(QueQ.peek()[0] == 0 && QueQ.peek()[1] == 0) && !(QueQ.peek()[0] == row - 1 && QueQ.peek()[1] == column - 1)) return true;
            
            for (int index = 0; index < QueQ.size(); index++) {


                int[] popedElements = QueQ.remove();
                int leftMost = popedElements[0], rightMostPoped = popedElements[1];


                if (rightMostPoped + 1 < column && board[leftMost][rightMostPoped + 1] == 1 && !visited[leftMost][rightMostPoped + 1]) {
                    visited[leftMost][rightMostPoped + 1] = true;
                    QueQ.add(new int[] {leftMost,rightMostPoped + 1});
                }




                if (leftMost + 1 < row && board[leftMost + 1][rightMostPoped] == 1 && !visited[leftMost + 1][rightMostPoped]) {
                    visited[leftMost + 1][rightMostPoped] = true;
                    QueQ.add(new int[] { leftMost + 1, rightMostPoped});
                }
            }
        }
        return false;
    }

}