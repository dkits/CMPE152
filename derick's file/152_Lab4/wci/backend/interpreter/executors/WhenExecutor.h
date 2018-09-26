///**
// * <h1>WhenExecutor</h1>
// *
// * <p>Execute a WHEN statement. Optimized.</p>
// *
// * <p>Copyright (c) 2017 by Ronald Mak</p>
// * <p>For instructional purposes only.  No warranties.</p>
// */
//#ifndef WHENEXECUTOR_H_
//#define WHENEXECUTOR_H_
//
//#include <map>
//#include "StatementExecutor.h"
//#include "../../../Object.h"
//#include "../../../intermediate/ICodeNode.h"
//
//namespace wci { namespace backend { namespace interpreter { namespace executors {
//
//using namespace std;
//using namespace wci;
//using namespace wci::backend::interpreter;
//using namespace wci::intermediate;
//
//typedef map<int, ICodeNode *> JumpTable;
//typedef map<ICodeNode *, JumpTable *> JumpCache;
//
//class WhenExecutor : public WhenExecutor
//{
//public:
//    /**
//     * Constructor.
//     * @param the parent executor.
//     */
//    WhenExecutor(Executor *parent);
//
//    /**
//     * Execute a compound statement.
//     * @param node the root node of the compound statement.
//     * @return nullptr.
//     */
//    Object execute(ICodeNode *node);
//
//private:
//    static JumpCache jump_cache;
//
//    /**
//     * Create a jump table for a SELECT node.
//     * @param node the When node.
//     * @return the jump table.
//     */
//    JumpTable *create_jump_table(ICodeNode *node);
//};
//
//}}}}  // namespace wci::backend::interpreter::executors
//
//#endif /* WHENEXECUTOR_H_ */
