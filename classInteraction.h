enum InteractionType {
	ATTACK = 0,
	CHEST = 1,
};
enum ObjectType {
	 Player,
	 Enemy,
};

class Interaction {
	private: 
		int id; 
		InteractionType type; // for example attack
		ObjectType source; // for example player 
		ObjectType target; // for example enemy
	public:
		Interaction(int id, int type, int source, int target); 
		int getId(){ return id;};
		InteractionType getType(){ return type;};
		ObjectType getSource(){ return source;};
		ObjectType getTarget(){ return target;};
		void setId(int newid){ id = newid;};
		void setType(InteractionType newtype){ type = newtype;};
		void setSource(ObjectType newsource){ source = newsource;};
		void setTarget(ObjectType newtarget){ target = newtarget;};
		void print(){ cout << "Interaction " << id << " of type " << type << " from " << source << " to " << target << endl;};

};
