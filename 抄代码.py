import pyautogui
import time

# 定义要替换的内容
x_values = [ 2, 3, 4, 5, 999, 998, 997 ]
text_values = [ 'set002', 'set003', 'set004', 'set005', 'set999', 'set998', 'set997']
# 模拟键盘输入
time.sleep(2)  # 等待2秒，以便切换到目标窗口
# 模拟输入的代码模板
for x_value, text_value in zip(x_values, text_values):
    code_template = f"""
	case {x_value}:if ({text_value}){text_value} = write_setting("{text_value}", 0); else {text_value} = write_setting("{text_value}", 1);control_set();
    
"""

    # 打印合并后的内容
    print(code_template)



    # 输入内容（逐个字符输入）
    for char in code_template:
        pyautogui.typewrite(char)
