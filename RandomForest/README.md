RandomForest
============

#前置准备


#训练文件格式
  仅支持csv格式
 
 
#配置文件说明
	
##训练参数
	-TRAIN_FILE_PATH		        训练文件路径
	-FOREST_TYPE                    森林的类型（分类/回归）
	-TREE_NUM				        森林的大小，即包含决策树的数量
	-MIN_TERMINAL_NODE_SIZE         终端节点（叶子节点）大小的最小值
	-MAX_NODE_NUM                   森林中每棵决策树的终端节点（叶子节点）个数的最大值,需程序内置最大值,若用户设置超出内置最大值，则发出警告
	-INSTANCE_SAMPLE_REPLACEMENT	对训练样本样例是否作有放回的采样,(true或false)，默认true(即有放回采样)
	-INSTANCE_SAMPLE_RATE	        对训练样本样例的采样率,(0,1],默认1
	-VARIABLE_SAMPLE_RATE           对预测变量的采样率,(0,1],默认0.7
	-VARIABLE_NUM                   预测变量个数
    -RESPONSE_VARIABLE_NUM          响应变量个数,默认1
    -VARIABLE_NAME_EXIST            预测变量名称是否存在,(true或false)，默认true(即每个预测变量对应各自的名称)
	-RESPONSE_VARIABLE_INDEX_SET	响应变量的索引值集合
	-VARIABLE_IMPORTANCE            是否评估预测变量的重要性,(true或false)，默认true(即需评估)
	-OUT_OF_BAG_ONLY                是否仅根据OOB数据评估精确度,(true或false)，默认false(即还需测试数据进行评估)
	-KEEP_FOREST                    是否保留随机森林数据到输出对象中,(true或false)，默认true
	-KEEP_PREDICT                   是否保留预测结果到输出对象中,(true或false)，默认true
	-MODEL_FILE_PATH                随机森林模型的输出路径
	
##测试参数
	-PREDICT_INPUT_FILE_PATH		测试文件路径
	-PREDICT_OUTPUT_FILE_PATH		预测结果文件的输出路径
	
##其他参数
	-EXCUTE_MODE		            程序执行模式,(CPU/OPENMP/CUDA),默认CPU
	-K_FOLD_CROSS_VALIDATION        K折交叉验证
	
##参数冲突说明
    -VARIABLE_SAMPLE_RATE           当没有给定预测变量个数时，根据预测变量采样率确定随机采样的预测变量个数
	-OUT_OF_BAG_ONLY                当该配置属性设置为0时，必须保证测试文件路径不为空
	-KEEP_FOREST & -MODEL_FILE_PATH 当保留随机森林数据时，必须保证森林模型输出路径不为空
	
	
#训练过程


#测试结果


#模型文件与加载


#库文件

