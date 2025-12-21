#!bin/bash

# 遍历当前目录下所有 .c 文件
for file in *.c; do
    # 跳过无匹配的情况（当没有 .c 文件时）
    [[ ! -f "$file" ]] && continue

    # 使用正则表达式匹配 x-y(-z).c 格式
    if [[ "$file" =~ ^([0-9]+)-([0-9]+)(-[0-9]+)?\.c$ ]]; then
        x="${BASH_REMATCH[1]}"           # 提取 x
        # y="${BASH_REMATCH[2]}"         # 可选：提取 y
        # z="${BASH_REMATCH[3]}"         # 可选：提取 -z 部分（含连字符）

        target_dir="ch_$x"

        # 如果目标目录不存在，则创建
        if [[ ! -d "$target_dir" ]]; then
            mkdir -p "$target_dir"
            echo "创建目录: $target_dir"
        fi

        # 移动文件
        mv "$file" "$target_dir/"
        echo "已移动: $file --> $target_dir/"
    else
        echo "跳过（不匹配格式）: $file"
    fi
done