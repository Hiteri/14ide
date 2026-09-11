-- DDL Data Definition
-- Criar Banco
create database Enzo
-- Colocar o Banco em Uso
use Enzo
-- Criar a tabela AMIGO
create table AMIGO
(cd_amigo int identity(1, 1) not null,
nm_amigo varchar(50) not null,
dt_nascimento date not null,
nr_telefone int null,
ds_email varchar(80) null,
constraint PK_AMIGO primary key(cd_amigo))

-- Pesquisa
select * from AMIGO
select nm_amigo, dt_nascimento, nr_telefone, ds_email from AMIGO
-- Selecionar Colunas
select nm_amigo, dt_nascimento from AMIGO
-- Renomear Colunas
select cd_amigo as 'ID',nm_amigo as 'Nome', dt_nascimento as 'Data de Nascimento', nr_telefone as 'Nº de telefone', ds_email as 'Email' from AMIGO
-- Condições ou Filtro
select * from AMIGO where nm_amigo='ANDRÉ LUIZ ARID'
-- Transaction
begin transaction
delete AMIGO
rollback transaction

update AMIGO set nm_amigo='CAIO', nr_telefone=5054040 where nm_amigo='AO TANAKA'
commit transaction

drop table AMIGO
delete AMIGO where cd_amigo > 12