#ifndef _BJOERN_BASIC_BLOCK_NODE_HPP
#define _BJOERN_BASIC_BLOCK_NODE_HPP

class BjoernFunctionNode;

class BjoernBasicBlockNode : public BjoernNode {
private:
	list<BjoernInstructionNode *> instructions;
	list<uint64_t> successors;
	BjoernFunctionNode *func;
public:
	BjoernBasicBlockNode() : BjoernNode()
	{
		type = "BasicBlock";
	}

	void addSuccessor(uint64_t suc)
	{
		successors.push_back(suc);
	}

	const list<uint64_t> & getSuccessors()
	{
		return successors;
	}

	void setFunc(BjoernFunctionNode *bjoernFunc)
	{
		func = bjoernFunc;
	}

	BjoernFunctionNode *getFunc()
	{
		return func;
	}
	
	void addInstruction(BjoernInstructionNode *node)
	{
		instructions.push_back(node);
	}

	const list<BjoernInstructionNode *> & getInstructions()
	{
		return instructions;
	}

	~BjoernBasicBlockNode()
	{
		freeInstructions();
	}

	void freeInstructions()
	{
		std::list<BjoernInstructionNode *>::const_iterator it;
		for (it = instructions.begin(); it != instructions.end(); ++it) {
			delete *it;
		}
	}

};

#endif
