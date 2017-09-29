#!/bin/env Rscript

library("magrittr")
library("tibble")
library("dplyr")
library("ggplot2")

args <- commandArgs(TRUE)

read.table(args[1]) %>%
	as_tibble() %>%
	rename(x = V1, y = V2) %>%
	{
		ggplot(., aes(x = x, y = y)) +
			geom_point()
	} %>%
	ggsave(args[2], plot = .)
	