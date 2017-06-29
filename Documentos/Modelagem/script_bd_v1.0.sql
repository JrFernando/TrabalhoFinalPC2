-- MySQL Script generated by MySQL Workbench
-- qui 29 jun 2017 20:09:44 -03
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema SCCE_BD
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema SCCE_BD
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `SCCE_BD` DEFAULT CHARACTER SET utf8 ;
USE `SCCE_BD` ;

-- -----------------------------------------------------
-- Table `SCCE_BD`.`Grupos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Grupos` (
  `grup_id` INT NOT NULL AUTO_INCREMENT,
  `grup_nome` VARCHAR(45) NOT NULL,
  `grup_descricao` VARCHAR(100) NULL,
  PRIMARY KEY (`grup_id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Funcionarios`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Funcionarios` (
  `func_id` INT NOT NULL AUTO_INCREMENT,
  `func_nome` VARCHAR(100) NOT NULL,
  `func_senha` VARCHAR(45) NULL,
  `func_salario` FLOAT NOT NULL,
  `func_grup_id` INT NOT NULL,
  PRIMARY KEY (`func_id`),
  INDEX `fk_Funcionarios_Categorias1_idx` (`func_grup_id` ASC),
  CONSTRAINT `fk_Funcionarios_Categorias1`
    FOREIGN KEY (`func_grup_id`)
    REFERENCES `SCCE_BD`.`Grupos` (`grup_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
COMMENT = 'A chave estrangeira não está como obrigatório porque a princípio não iremos implementar o layer em amarelo.';


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Fabricantes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Fabricantes` (
  `fabr_id` INT NOT NULL AUTO_INCREMENT,
  `fabr_nome` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`fabr_id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Produtos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Produtos` (
  `prod_id` INT NOT NULL AUTO_INCREMENT,
  `prod_nome` VARCHAR(100) NOT NULL,
  `prod_quantidade` INT NOT NULL DEFAULT 0,
  `prod_preco_compra` FLOAT NOT NULL,
  `prod_preco_venda` FLOAT NOT NULL,
  `prod_fabr_id` INT NOT NULL,
  PRIMARY KEY (`prod_id`),
  INDEX `fk_Produtos_Fabricantes_idx` (`prod_fabr_id` ASC),
  CONSTRAINT `fk_Produtos_Fabricantes`
    FOREIGN KEY (`prod_fabr_id`)
    REFERENCES `SCCE_BD`.`Fabricantes` (`fabr_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Caixas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Caixas` (
  `caix_id` INT NOT NULL AUTO_INCREMENT,
  `caixa_saldo` FLOAT NOT NULL DEFAULT 0,
  PRIMARY KEY (`caix_id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Turnos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Turnos` (
  `turn_func_id` INT NOT NULL,
  `turn_caix_id` INT NOT NULL,
  `turn_horario_inicio` DATETIME NOT NULL,
  `turn_horario_fim` DATETIME NULL,
  PRIMARY KEY (`turn_func_id`, `turn_caix_id`, `turn_horario_inicio`),
  INDEX `fk_Funcionarios_has_Caixas_Caixas1_idx` (`turn_caix_id` ASC),
  INDEX `fk_Funcionarios_has_Caixas_Funcionarios1_idx` (`turn_func_id` ASC),
  CONSTRAINT `fk_Funcionarios_has_Caixas_Funcionarios1`
    FOREIGN KEY (`turn_func_id`)
    REFERENCES `SCCE_BD`.`Funcionarios` (`func_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Funcionarios_has_Caixas_Caixas1`
    FOREIGN KEY (`turn_caix_id`)
    REFERENCES `SCCE_BD`.`Caixas` (`caix_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Compras`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Compras` (
  `comp_id` INT NOT NULL,
  `comp_caix_id` INT NOT NULL,
  `comp_prod_id` INT NOT NULL,
  `comp_qtd_produto` INT NOT NULL,
  `comp_horario` DATETIME NULL,
  `comp_func_id` INT NULL,
  PRIMARY KEY (`comp_id`, `comp_caix_id`, `comp_prod_id`),
  INDEX `fk_Caixas_has_Produtos_Produtos1_idx` (`comp_prod_id` ASC),
  INDEX `fk_Caixas_has_Produtos_Caixas1_idx` (`comp_caix_id` ASC),
  INDEX `fk_Compras_Funcionarios1_idx` (`comp_func_id` ASC),
  CONSTRAINT `fk_Caixas_has_Produtos_Caixas1`
    FOREIGN KEY (`comp_caix_id`)
    REFERENCES `SCCE_BD`.`Caixas` (`caix_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Caixas_has_Produtos_Produtos1`
    FOREIGN KEY (`comp_prod_id`)
    REFERENCES `SCCE_BD`.`Produtos` (`prod_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Compras_Funcionarios1`
    FOREIGN KEY (`comp_func_id`)
    REFERENCES `SCCE_BD`.`Funcionarios` (`func_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Modulos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Modulos` (
  `modu_id` INT NOT NULL AUTO_INCREMENT,
  `modu_nome` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`modu_id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Permissoes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Permissoes` (
  `perm_grup_id` INT NOT NULL,
  `perm_modu_id` INT NOT NULL,
  PRIMARY KEY (`perm_grup_id`, `perm_modu_id`),
  INDEX `fk_Grupos_has_Modulos_Modulos1_idx` (`perm_modu_id` ASC),
  INDEX `fk_Grupos_has_Modulos_Grupos1_idx` (`perm_grup_id` ASC),
  CONSTRAINT `fk_Grupos_has_Modulos_Grupos1`
    FOREIGN KEY (`perm_grup_id`)
    REFERENCES `SCCE_BD`.`Grupos` (`grup_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Grupos_has_Modulos_Modulos1`
    FOREIGN KEY (`perm_modu_id`)
    REFERENCES `SCCE_BD`.`Modulos` (`modu_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Movimentações`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Movimentações` (
  `movi_func_id` INT NOT NULL,
  `movi_caix_id` INT NOT NULL,
  `movi_horario` DATETIME NOT NULL,
  `movi_valor` FLOAT NOT NULL,
  PRIMARY KEY (`movi_func_id`, `movi_caix_id`, `movi_horario`),
  INDEX `fk_Funcionarios_has_Caixas_Caixas2_idx` (`movi_caix_id` ASC),
  INDEX `fk_Funcionarios_has_Caixas_Funcionarios2_idx` (`movi_func_id` ASC),
  CONSTRAINT `fk_Funcionarios_has_Caixas_Funcionarios2`
    FOREIGN KEY (`movi_func_id`)
    REFERENCES `SCCE_BD`.`Funcionarios` (`func_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Funcionarios_has_Caixas_Caixas2`
    FOREIGN KEY (`movi_caix_id`)
    REFERENCES `SCCE_BD`.`Caixas` (`caix_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Reposições`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Reposições` (
  `repo_func_id` INT NOT NULL,
  `repo_prod_id` INT NOT NULL,
  `repo_horario` DATETIME NOT NULL,
  `repo_quantidade` INT NOT NULL,
  PRIMARY KEY (`repo_func_id`, `repo_prod_id`, `repo_horario`),
  INDEX `fk_Funcionarios_has_Produtos_Produtos1_idx` (`repo_prod_id` ASC),
  INDEX `fk_Funcionarios_has_Produtos_Funcionarios1_idx` (`repo_func_id` ASC),
  CONSTRAINT `fk_Funcionarios_has_Produtos_Funcionarios1`
    FOREIGN KEY (`repo_func_id`)
    REFERENCES `SCCE_BD`.`Funcionarios` (`func_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Funcionarios_has_Produtos_Produtos1`
    FOREIGN KEY (`repo_prod_id`)
    REFERENCES `SCCE_BD`.`Produtos` (`prod_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `SCCE_BD`.`Empresa`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `SCCE_BD`.`Empresa` (
  `empr_nome` VARCHAR(45) NOT NULL,
  `empr_cnpj` VARCHAR(45) NOT NULL,
  `empr_endereco` VARCHAR(100) NOT NULL)
ENGINE = InnoDB
COMMENT = 'Apenas para guardar as informações da empresa. Por isso no singular, sem ligações com as demais tabelas e sem identificador por que deve conter apenas um registro. Garantir isso no programa.';


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
