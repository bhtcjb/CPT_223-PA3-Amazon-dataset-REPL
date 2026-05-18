# CPT_223-PA3-Amazon-dataset-REPL
REPL supporting listInventory and find commands for Amazon products dataset utilizing hash tables for CPT_223 class

# Assignment Documentation

## Implimentation
To support a find and listInventory command, this REPL system employs two hash tables implimented as a dynamic array of linked lists. Using std::hash as the hash function, if two keys hash to the same index, they are simply inserted to the front of the linked list. Each insert into the hash table checks if the load factor will be above 0.75, and if so, the size of the array is doubled and all data is rehashed with the new capacity. 

The find command uses a hash table keyed by product id. Since id's are unlikely to hash to the same index, searching has a time complexity of O(1) and generally requires checking only one key on average.

The listInventory command uses a hash table keyed by category. For simple implimentation of this concept, each same-category product is simply inserted with the same key. This means searching generally has a time complexity of O(c) where c is number of products within a certain category. An O(c) time complexity is the best case scenario as the command always prints every value in the category, but if multiple seperate categories are hashed to the same index, the time complexity could increase multiplicatively. Additionally, multiple categories are assigned to the same product, meaning the same data is often inserted multiple times. This trades memory for speed, so that the information can be immediately retrieved from the corresponding index.

## Data Cleaning
The product file contains 1 product per line, with 28 fields delimited by comma. Products only appear once and all products have the same number of fields in the same order, thus checks were not needed for duplicates or field differences. However, many fields were empty. Each of these were read in as NA. Fields with quotes but no containing text were also read in as NA. Product id was always assumed to exist. Fields containing NA were not printed when calling the REPL commands.

Additionally, many fields contained quotes. Within quoted sections, commas should not be read as a delimiter. Quoting was inconsistant across products, meaning quotes could not be assumed to exist or not. Quotes within a quoted field were indicated by two sequential quotes. When being parsed, first and last quotes were removed from quoted sections, as well as one of each sequential quotes within the quoted field. For simplicity all fields were checked for quotes.

Lastly, I found some problematic byte sequences , starting with unicode 0xC2, that would cause the terminal to get stuck. I made a check for it to remove when parsing, which fixes it in this particular case, but I do not know if there are other problem characters in the file.

The hash table for the find command read the product id in as the key and all subsequent fields were read into a container as the value for that corresponding key. 
The hash table for the listInventory command seperated each category as delimited by two spaces surounding a vertical bar, before reading in as the key. Product id and name was read into a container as the value multiple times for each corresponding category key.

## Test Cases
Operations for the linked list and hash table were tested using cassert. 

### Linked List Test Functions
Linked list testBasic() tests the simple operations used in later test functions. This includes ensuring that the object (and iterator) initializes correctly and tests simple functions like getValue(), getKey(), empty(), or atEnd() for correct return value. Since inserting is required to test these functions, basic insert() is also tested. Two inserts are made to test correct linkage and correct iteration through the list.

Linked list testInsert() tests various cases for insert(). First it checks if inserting at a past the end iterator results in a failed insert as expected. Then inserts three times to give opportunity to test inserting in various positions. With this implimentation, there is technically only one condition for inserting with an iterator, but inserting at front, middle, and end positions is still tested for redundancy or potentially finding off by one errors.

Linked list testRemove() tests various cases for remove(). First it tests remove failure to remove from empty list. Then populates the list with basic inserts. To check for connectivity issues, chained removal operations are tested until the list is empty. Then the list is populated again to test removing at a specified key. Removal from front and middle positions are both tested since these have different conditions. Remove from end has the same condition as remove from middle, but is also tested for redundancy or potentially finding off by one errors. Failing to remove a non-existant key is tested, and then the list is emptied to check if any connectivity issues pop up.

Linked list testFind() tests various cases for find(). First it populates list. Then failure to find non-existant key is tested. Then successfully finding keys that do exist is tested at various positions including, front, middle, and end for redundancy or potentially finding off by one errors. The expected behavior that it will only find the first of duplicates is also tested.

### Hash Table Test Functions
Hash table testBasic() tests the simple operations used in later test functions. This includes ensureing that the object initializes correctly and tests simple functions like getCapacity() and getSize(). Since inserting helps test multiple cases of these functions, basic insert() is also tested.

Hash table testInsert() tests various cases for insert(). First six regular insertions are made to test normal case. Then, a seventh insertion triggers a rehash to test if resizing and rehashing are successful. Another insertion is made after the rehash to ensure nothing was broken during rehashing.

Hash table testFind() tests various cases for find(). First the table is populated with six inserts, including three duplicates. Then tests failure to find a non-existant key. It finds a series of unique keys to test normal find case. Also, tested is finding the first key in duplicate bucket to test iterating through a single bucket. A seventh insertion is made to trigger rehash, and a series of find operations are made to ensure nothing was broken during rehashing.

Hash table testRemove() tests various cases for remove(). First the table is populated with six inserts, including three duplicates. Fail case was tested for non-existant key. Then normal remove case was tested for single values. Removal of duplicate values was tested for expected behavior that first duplicate in the linked list would be removed. Removal was tested until empty. Then, again to ensure rehashing did not break anything, the table was repopulated to trigger rehash, and removal until empty was tested post-rehash in a similar fashion.
