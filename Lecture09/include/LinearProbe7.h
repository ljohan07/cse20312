#ifndef LINEARPROBE7_H
#define LINEARPROBE7_H

#include <iostream>
#include <vector>

enum EntryState { ACTIVE, EMPTY, DELETED };

template<class Key, class Value>
class HashTable{
	
	private:
	
		// Private Struct Hash Entry
		struct HashEntry{
			
			Key key;
			Value value;
			EntryState state;
			
			HashEntry() : key(), value(), state( EMPTY ) {}
			
			HashEntry( std::pair<const Key, Value> thePair, EntryState stateIn = EMPTY ) 
				: key(thePair.first), value(thePair.second), state( stateIn ) {}

		};
	
		std::vector< HashEntry > array;	// Private Dynamic Array for Hash Table
		unsigned int numHash;			// Number of Hashed Elements
		
		// Checks if the value is a Primt
		bool isPrime( long unsigned int n ) const{
			
			if( n == 2 || n == 3){
				return true;
			}
			
			if( n == 1 || n % 2 == 0 ){
				return false;
			}
			
			for( long unsigned int i = 3; i * i <= n; i += 2 ){
				if( n % i == 0 ){
					return false;
				}
			}
			
			return true;
		}

		// Obtains the next Prime
		long unsigned int nextPrime( long unsigned int n ) const{
			
			// If n is even, make it odd
			if( n % 2 == 0 ){
				++n;
			}
			
			for( ; !isPrime(n); n+=2 ){
				// Do Nothing
			}
			
			return n;
		}

		
		// Translate to unsigned int for int
		long unsigned int HashFunc( const int& keyToTranslate ) const{
				
			if (keyToTranslate < 0){
				return (long unsigned int)(-1 * keyToTranslate);
			}
			
			return (long unsigned int) keyToTranslate;
			
		}

		// Translate to unsigned int for std::string		
		long unsigned int HashFunc( const std::string& keyToTranslate ) const{
			
			return keyToTranslate.size();
			
		}

		// Return Hash Location
		long unsigned int findPos( const Key& theKey ) const{
			
			long unsigned int currentPos;
			long unsigned int iter = 0;
			const unsigned int STEPSIZE = 1;
			
			do{
				// Hash Function determines current position
				currentPos = (HashFunc( theKey ) + iter*STEPSIZE) % array.capacity();
				++iter;
			}
			while(
				array.at( currentPos ).state != EMPTY
				&& array.at( currentPos ).state != DELETED
				&& array.at( currentPos ).key != theKey
				&& iter < array.capacity()
			);
			
			// Return capacity if the current value isn't the key. For safety
			if(array.at( currentPos ).state == ACTIVE 
				&& array.at( currentPos ).key != theKey ){
					
					return array.capacity();
					
				}
			
			return currentPos;
			
		}
		
		// Rehash the Dynamic Array
		void rehash(){
			
			// Copy the element 
			std::vector<HashEntry> oldArray = array;
			
			// Clear the original array 
			array.clear();
			
			// Resize the array 
			array.resize( nextPrime( oldArray.size() + 1 ) );
			
			// Rehash the old elements 
			numHash = 0; // Set the number hashed to 0
			for( long unsigned int iter = 0; iter < oldArray.capacity(); iter++ ){
				
				if( oldArray[iter].state == ACTIVE ){
					
					// Insert using the std::pair {} template
					insert( { oldArray[iter].key, oldArray[iter].value } );
					
				}
			}
		}
		
	public:
	
		// Constructor
		HashTable(const unsigned int size = 0) : array( nextPrime(size) ), numHash(0) { }
		
		// Insert into the hash 
		void insert( const std::pair<Key, Value>& insertPair ){
			
			// If another insert exceeds half capacity, rehash
			if( numHash + 1 > array.capacity() / 2 ){
				
				rehash();
			}
			
			// We will always increment the Hash if we get here
			++numHash;
			
			// Get the location
			long unsigned int location = findPos( insertPair.first );
			
			// Insert the new entry at the current position
			HashEntry theEntry(insertPair, ACTIVE);
			array[ location ] = theEntry;
			
		}
		
		
		bool remove( const Key& theKey ){
			
			long unsigned int currentPos = findPos( theKey );
			
			// If it's not active - Not in the Hash 
			if( array [ currentPos ].state != ACTIVE ){
				return false;
			}
			
			// Lazy Deletion
			array[ currentPos ].state = DELETED;
			
			// Decrement the Hash
			--numHash;
			
			return true;
		}
	
		// Overloaded Friend Operator
		friend std::ostream& operator<<( std::ostream& output, const HashTable<Key, Value>& theTable ){
			
			output << "Hash Table Size: " << theTable.array.size() << std::endl;
			output << "Hashed Elements: " << theTable.numHash << std::endl;
			
			for(unsigned int iter = 0; iter < theTable.array.size(); iter++){
				
				output << "{" << iter << ": ";
				
				if( theTable.array[iter].state == ACTIVE ){
				
					output << "ACTIVE, ";
				
				}
				else if( theTable.array[iter].state == DELETED ){
				
					output << "DELETED, ";
				
				}
				else{
					
					output << "EMPTY, ";
				}
				
				output << theTable.array[iter].key << ", ";
				
				output << theTable.array[iter].value << "}" << std::endl;
				
			}
			
			return output;
		}
};

#endif