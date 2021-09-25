int lengthOfLongestSubstring(char * s){
    int max = 0;
    int temp_max = 0;
    int current = 0;
    int repeating_char = 0;
    int new_start = 0;
    int flag = 0;
    
    if(s[current] == '\0') return 0;

    while (s[current] != '\0'){
        
       	for (repeating_char = current-1; repeating_char >= new_start; repeating_char--){
			if (s[repeating_char] == s[current]){
				flag = 1;
				break;
			}
		} 
        
        
        if (flag == 0) {
			temp_max++;
        }
		else {
			new_start = repeating_char + 1;
			temp_max = current - new_start + 1;
			flag = 0;
		}        
        
        if (temp_max > max)	max = temp_max;
		current++;
        
    }
    
    return max;
}