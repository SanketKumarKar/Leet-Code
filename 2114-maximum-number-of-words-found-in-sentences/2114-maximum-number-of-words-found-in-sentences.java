class Solution {
    public int mostWordsFound(String[] sentences) {
        int Maxcount = 0;
        int count = 0;
        for (int i = 0; i < sentences.length; i++) {
            count = sentences[i].split(" ").length;
            Maxcount = Math.max(Maxcount, count);
        }
        return Maxcount;
    }
}