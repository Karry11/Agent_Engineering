# 打开原始文件
with open('original.txt', 'r', encoding='utf-8') as file:
    # 读取所有行，并去掉每行的首尾空白符
    lines = [line.strip() for line in file]

# 移除列表中所有的空字符串，这样就可以去除空行
lines = [line for line in lines if line]

# 将处理后的非空行合并到一起，并用回车符连接，如果也想去除行内的所有空格，请在前一步解除注释
processed_content = "\n".join(lines)

# 将处理后的内容保存到新文件
with open('processed.txt', 'w', encoding='utf-8') as file:
    file.write(processed_content)